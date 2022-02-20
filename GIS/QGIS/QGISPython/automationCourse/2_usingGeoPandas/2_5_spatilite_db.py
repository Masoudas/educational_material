"""
"""
import sqlite3

import geopandas as gpd
import shapely.wkb as swkb
from geoalchemy2 import Geometry, WKTElement
from sqlalchemy import MetaData, create_engine, event
from sqlalchemy.engine.url import URL
from sqlalchemy.orm import sessionmaker

# Database info. Me: And I honestly didn't know that this things existed.
db_url = URL(drivername='postgresql+psycopg2', host=HOST, database=DB,
             username=USER, port=PORT, password=PWD)

# Create engine
engine = create_engine(db_url)

# Init Metadata
meta = MetaData()

# Load table definitions from db
meta.reflect(engine)

# Create session
Session = sessionmaker(bind=engine)
session = Session()

# ========================
# Read data from PostGIS
# ========================

# Specify sql query
sql = "SELECT * FROM finland;"

# Pull the data
data = gpd.read_postgis(sql=sql, con=engine)

# Close session
session.close()

# DB path
dbfp = 'L2_data/Finland.sqlite'

# Name for the table
tbl_name = 'finland'

# SRID (crs of your data)
srid = 4326

# Parse Geometry type of the input Data
gtype = data.geom_type.unique()
assert len(gtype) == 1, "Mixed Geometries! Cannot insert into SQLite table."
geom_type = gtype[0].upper()

# Initialize database engine
engine = create_engine('sqlite:///{db}'.format(db=dbfp), module=sqlite3)

# Initialize table without geometries
geo = data.drop(['geometry'], axis=1)

with sqlite3.connect(dbfp) as conn:
    geo.to_sql(tbl_name, conn, if_exists='replace', index=False)

# Enable spatialite extension
with sqlite3.connect(dbfp) as conn:
    conn.enable_load_extension(True)
    conn.load_extension("mod_spatialite")
    conn.execute("SELECT InitSpatialMetaData(1);")
    # Add geometry column with specified CRS with defined geometry typehaving two dimensions
    conn.execute(
        "SELECT AddGeometryColumn({table}, 'wkb_geometry',\
        {srid}, {geom_type}, 2);".format(table=tbl_name, srid=srid, geom_type=geom_type)
    )

# Convert Shapely geometries into well-known-binary format
data['geometry'] = data['geometry'].apply(lambda geom: swkb.dumps(geom))

# Push to database (overwrite if table exists)
data.to_sql(tbl_name, engine, if_exists='replace', index=False)
