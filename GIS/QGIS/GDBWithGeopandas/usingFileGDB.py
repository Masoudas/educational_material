"""
To write to gdbs, we need to have fileGDB installed, which is part of GDAL.

To install GDAL, we need to do the following:
$ sudo apt-get install python3.6-dev
$ sudo add-apt-repository ppa:ubuntugis/ppa
$ sudo apt-get update
$ sudo apt-get install libgdal-dev
$ export CPLUS_INCLUDE_PATH=/usr/include/gdal # Add to .bashrc
$ export C_INCLUDE_PATH=/usr/include/gdal # Add to .bashrc
$ pip install GDAL
"""