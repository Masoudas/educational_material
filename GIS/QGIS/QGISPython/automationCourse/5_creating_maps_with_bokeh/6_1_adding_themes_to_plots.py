"""
With Bokeh’s themes, you can quickly change the appearance of your plot. Themes are a set of pre-defined design parameters such as colors, fonts, or line styles.

Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast. Additionally, you can define your own custom themes.

To use one of the built-in themes, assign the name of the theme you want to use to the theme property of your document. (Me: As such, we see that curdoc from bokeh.io is responsible for defining new fields in the document. Perhaps, to define for example right to left labels, I need to use this.)
"""
from bokeh.io import curdoc
from bokeh.plotting import figure, show

# prepare some data
x = [1, 2, 3, 4, 5]
y = [4, 5, 5, 7, 2]

# apply theme to current document
curdoc().theme = "dark_minimal"

# create a plot
p = figure(sizing_mode="stretch_width", max_width=500, height=250)

# add a renderer
p.line(x, y)

# show the results
show(p)
