"""
This is a very cool feature. We can allow figures to move together (aka linked panning, as the 
following example demonstrates.) Note that the way to do so is to set the range of one plot equivalent to the range of the other one.
"""
import numpy as np
from bokeh.plotting import figure


tools = 'pan'

N = 100
x = np.linspace(0, 4 * np.pi, N)
y1 = np.sin(x)
y2 = np.cos(x)
y3 = np.sin(x) + np.cos(x)

s1 = figure(tools=tools)
s1.circle(x, y1, color="navy", size=8, alpha=0.5)
s2 = figure(tools=tools, x_range=s1.x_range, y_range=s1.y_range)
s2.circle(x, y2, color="firebrick", size=8, alpha=0.5)
s3 = figure(tools='pan, box_select', x_range=s1.x_range)
s3.circle(x, y3, color="olive", size=8, alpha=0.5)
