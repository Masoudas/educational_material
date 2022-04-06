"""
Inside the view file, we can simply return an string, as follows.

This is the simplest view possible in Django. To call the view, we need to map it to a URL - and for this we need a URLconf.

Now, CREATE a urls.py inside the polls project, and then add the path to it
###
from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
]
###

The next step is to point the root URLconf at the polls.urls module. In mysite/urls.py, add an import for django.urls.include and insert an include() in the urlpatterns list, so you have:
###
from django.urls import include, path

urlpatterns = [
    path('polls', include('polls.urls'))
]
###
The include() function allows referencing other URLconfs. Whenever Django encounters include(), it chops off whatever part of the URL matched up to that point and sends the remaining string to the included URLconf for further processing.
"""

from django.http import HttpResponse


def index(request):
    return HttpResponse("Hello, polling application")
