"""
Even a simple graph like this line chart has interactive features. Use the tools on the right of the plot to explore:

    -   Icon representing the pan tool Use the pan tool to move the graph within your plot.
    -   Icon representing box zoom Use the box zoom tool to zoom into an area of your plot.
    -   Icon representing the wheel zoom Use the wheel zoom tool to zoom in and out with a mouse wheel.
    -   Icon representing the save tool Use the save tool to export the current view of your plot as a PNG file.
    -   Icon representing the reset tool Use the reset tool to return your view to the plot’s default settings.
    -   Help symbol Use the help symbol to learn more about the tools available in Bokeh.

"""
from bokeh.plotting import figure, show

# prepare some data
x = [1, 2, 3, 4, 5]
y = [6, 7, 2, 4, 5]

# Notice that all of these are optional parameters.
p = figure(
    width=1600, height=500,
    title="Simple line example", x_axis_label='x', y_axis_label='y')

# Add a line graph
p.line(x=x, y=y, legend_label="Temp.", line_width=2)

# To show the generated html.
show(p)
