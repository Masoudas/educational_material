"""
Inside the view file, we can simply return an string, as follows:

https://docs.djangoproject.com/en/4.0/intro/tutorial01/
"""

from django.http import HttpResponse


def index(request):
    return HttpResponse("Hello, polling application")
