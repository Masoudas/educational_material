"""
The installation can be done using pip:
$ pip install bokeh

We can check that bokeh exists as follows:
$ bokeh info

To download the sample data, we can either run the following script, or we can download using the bokeh command line:
$ bokeh sampledata

The command line tools has some stuff! This Includes 'build a bokeh extension', 'init a bokeh extension', 'serve to run a bokeh server hosting one or more applications', etc.

We may also install the following custom modules:
In addition to the required dependencies, some additional packages are necessary for certain optional features:

    -   NodeJS
Necessary for Extending Bokeh or for defining CustomJS implementations in TypeScript.

    -   NetworkX
Necessary to use the from_networkx() function to generate Bokeh graph renderers directly from NetworkX data.

    -   pandas
Necessary for the hexbin() function. Additionally, having pandas installed makes some aspects of Bokeh simpler to use. For example, glyph functions are able to automatically convert pandas DataFrames to Bokeh data sources.

    -   psutil  
Necessary to enable detailed memory logging in the Bokeh server.

    -   Selenium, GeckoDriver, Firefox
Necessary for Exporting plots to PNG and SVG images.

    -   Sphinx
Necessary to make use of the bokeh.sphinxext Sphinx extension for including Bokeh plots in Sphinx documentation.
"""
from bokeh.sampledata import download

# To download sample data
download(progress=True)
