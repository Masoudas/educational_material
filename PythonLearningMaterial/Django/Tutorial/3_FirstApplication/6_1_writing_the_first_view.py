"""
Inside the view file, we can simply return an string, as follows:


"""

from django.http import HttpResponse


def index(request):
    return HttpResponse("Hello, polling application")
