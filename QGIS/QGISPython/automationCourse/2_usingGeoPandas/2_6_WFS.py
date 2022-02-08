"""
We can also directly handle WFS
"""
import geopandas as gpd
import requests
import geojson

# Specify the url for the backend. Here we are using data from Statistics Finland: https://www.stat.fi/org/avoindata/paikkatietoaineistot_en.html
url = 'http://geo.stat.fi/geoserver/vaestoruutu/wfs'

# Specify parameters (read data in json format).
# Available feature types in this particular data source: http://geo.stat.fi/geoserver/vaestoruutu/wfs?service=wfs&version=2.0.0&request=describeFeatureType
params = dict(service='WFS', version='2.0.0', request='GetFeature',
              typeName='vaestoruutu:vaki2017_5km', outputFormat='json')

# Fetch data from WFS using requests
r = requests.get(url, params=params)

# Create GeoDataFrame from geojson
data = gpd.GeoDataFrame.from_features(geojson.loads(r.content))

data.to_csv("finland.csv")

print(data)
