from bokeh.plotting import figure, show
from bokeh.sampledata.iris import flowers

colormap = {'setosa': 'red', 'versicolor': 'green', 'virginica': 'blue'}
colors = [colormap[x] for x in flowers['species']]

p = figure(title="به جان خودوم فونتش قشنگ نیه")
p.xaxis.axis_label = 'ننه'
p.yaxis.axis_label = 'آخ ننه'
p.yaxis.axis_loc = "right"

p.scatter(flowers["petal_length"], flowers["petal_width"],
          color=colors, fill_alpha=0.2, size=10)

show(p)
