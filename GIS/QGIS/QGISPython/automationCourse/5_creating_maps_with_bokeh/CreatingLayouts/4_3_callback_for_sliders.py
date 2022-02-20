"""
Next, is the plot that demonstrates how to create custom callback functions for interactive elements. 

This is done, using the CustomJS class. Note that we pass our models (interactive elements) using the args parameter as a dictionary. These are provided as even_arguments for our event handler. As such, we're able to handle them, by creating our own JavaScript snippet (and not python as I thought). In particular, we access the current value of our sliders. Also, note that to access data, we've passed it as a ColumnDataSource.

Notice also how we define widgets as a single column as well.
"""
import numpy as np
from bokeh.plotting import ColumnDataSource, figure, column, show, gridplot
from bokeh.models import Slider, CustomJS

x = np.linspace(0, 10, 100)
y = np.sin(x)

source = ColumnDataSource(data=dict(x=x, y=y))

plot = figure(
    y_range=(-10, 10), tools='', toolbar_location=None,
    title="Sliders example")
plot.line('x', 'y', source=source, line_width=3, line_alpha=0.6)

amp_slider = Slider(start=0.1, end=10, value=1, step=.1, title="Amplitude")
freq_slider = Slider(start=0.1, end=10, value=1,
                     step=.1, title="Frequency")
phase_slider = Slider(start=0, end=6.4, value=0, step=.1, title="Phase")
offset_slider = Slider(start=-5, end=5, value=0, step=.1, title="Offset")

callback = CustomJS(
    args=dict(
        source=source, amp=amp_slider, freq=freq_slider, phase=phase_slider, offset=offset_slider),
    code="""
    const data = source.data;
    const A = amp.value;
    const k = freq.value;
    const phi = phase.value;
    const B = offset.value;
    const x = data['x']
    const y = data['y']
    for (let i = 0; i < x.length; i++) {
        y[i] = B + A*Math.sin(k*x[i]+phi);
    }
    source.change.emit();
""")

amp_slider.js_on_change('value', callback)
freq_slider.js_on_change('value', callback)
phase_slider.js_on_change('value', callback)
offset_slider.js_on_change('value', callback)

widgets = column(amp_slider, freq_slider, phase_slider, offset_slider)

plot = gridplot([[widgets, plot]])
show(plot)
