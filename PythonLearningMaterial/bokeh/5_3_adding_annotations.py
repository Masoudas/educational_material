"""
Annotations are visual elements that you add to your plot to make it easier to read. For more information on the various kinds of annotations, see Adding annotations in the user guide.

One example are box annotations. You can use box annotations to highlight certain areas of your plot.

The import is from the models subpackage. We add them using the add_layout package. Notice that for
example, we use two boxes to add two colored boxed on top of one another.
"""
import random

# For box annotation.
from bokeh.models import BoxAnnotation
from bokeh.plotting import figure, show

# generate some data (1-50 for x, random values for y)
x = list(range(0, 51))
y = random.sample(range(0, 100), 51)

# create new plot
p = figure(title="Box annotation example")

# add line renderer
line = p.line(x, y, line_color="#000000", line_width=2)

# add box annotations
low_box = BoxAnnotation(
    top=20, fill_alpha=0.2, fill_color="#F0E442")
mid_box = BoxAnnotation(
    bottom=20, top=80, fill_alpha=0.2, fill_color="#009E73")
high_box = BoxAnnotation(
    bottom=80, fill_alpha=0.2, fill_color="#F0E442")

# add boxes to existing figure
p.add_layout(low_box)
p.add_layout(mid_box)
p.add_layout(high_box)

# show the results
show(p)
