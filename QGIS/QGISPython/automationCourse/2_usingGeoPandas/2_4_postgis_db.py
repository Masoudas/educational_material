"""
postgis is a databse, and as such uses a combination of sqlalchemy and geoalchemy2 to work with the database.
"""
from sqlalchemy.engine.url import URL
from sqlalchemy import create_engine
from sqlalchemy import MetaData
from sqlalchemy.orm import sessionmaker
from geoalchemy2 import WKTElement, Geometry
import geopandas as gpd

# Update with your db parameters
HOST = '123.234.345.16'
DB = 'my_database'
USER = 'my_user'
PORT = 5432
PWD = 'my_password'

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

# =========================================
# Write data to PostGIS (make a copy table)
# =========================================

# Coordinate Reference System (srid)
crs = 4326

# Target table
target_table = 'finland_copy'

# Convert Shapely geometries to WKTElements into column 'geom' (default in PostGIS)
data['geom'] = data['geometry'].apply(
    lambda row: WKTElement(row.wkt, srid=crs))

# Drop Shapely geometries
data = data.drop('geometry', axis=1)

# Write to PostGIS (overwrite if table exists, be careful with this! )
# Possible behavior: 'replace', 'append', 'fail'

data.to_sql(target_table, engine, if_exists='replace', index=False)
