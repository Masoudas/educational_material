"""
The circle() function, for example, lets you define aspects like the color or diameter of the circles:

    -   fill_color: the fill color of the circles
    -   fill_alpha: the transparency of the fill color (any value between 0 and 1)
    -   line_color: the fill color of the circles’ outlines
    -   size: the size of the circles (in screen units or data units)
    -   legend_label: legend entry for the circles

For example, passing "yellow" to a circle’s color property is the same as setting fill_color and line_color to yellow individually.

In Bokeh, you can specify colors in several ways. For example:
    -   Use one of the named CSS colors (for example, "firebrick")
    -   Use hexadecimal values, prefaced with a # (for example "#00ff00")
    -   Use a 3-tuple for RGB colors (for example, (100, 100, 255)
    -   Use a 4-tuple for RGBA colors (for example (100, 100, 255, 0.5))
"""
from bokeh.plotting import figure, show

# prepare some data
x = [1, 2, 3, 4, 5]
y = [4, 5, 5, 7, 2]

# create a new plot with a title and axis labels
p = figure(title="Glyphs properties example",
           x_axis_label="x", y_axis_label="y")

# add circle renderer with additional arguments
p.circle(
    x, y, legend_label="Objects", fill_color="red", fill_alpha=0.5, line_color="blue",
    size=80)

# show the results
show(p)
