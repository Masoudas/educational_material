"""
To make plots fit to page, use the "stretch_width" property of the width and height. 
"""
from bokeh.plotting import figure, show

# prepare some data
x = [1, 2, 3, 4, 5]
y = [4, 5, 5, 7, 2]

# create a new plot with responsive width
p = figure(
    title="Plot responsive sizing example",
    sizing_mode="stretch_width",
    height="stretch_height",
    x_axis_label="x",
    y_axis_label="y",
)

# add circle renderer
circle = p.circle(x, y, fill_color="red", size=15)

# show the results
show(p)
