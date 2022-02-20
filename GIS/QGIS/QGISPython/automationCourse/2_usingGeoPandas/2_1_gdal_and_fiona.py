"""
ME: Recall that GDAL is the driver library for managing various databases. GDAL is apparently imported as a fiona package.

Install GDAL itself as follows:
$ sudo add-apt-repository ppa:ubuntugis/ppa && sudo apt-get update
$ sudo apt-get update
$ sudo apt-get install gdal-bin
$ sudo apt-get install libgdal-dev

Fiona is GDAL’s neat and nimble vector API for Python programmers.

Fiona is designed to be simple and dependable. It focuses on reading and writing data in standard Python IO style and relies upon familiar Python types and protocols such as files, dictionaries, mappings, and iterators instead of classes specific to OGR. Fiona can read and write real-world data using multi-layered GIS formats and zipped virtual file systems and integrates readily with other Python GIS packages such as pyproj, Rtree, and Shapely. Fiona is supported only on CPython versions 2.7 and 3.4+.
"""
from fiona.drvsupport import supported_drivers

print(supported_drivers)
