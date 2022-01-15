"""
Once your models are defined, Django can automatically create a professional, production ready administrative interface - a website that lets authenticated users add, change and delete objects. The only step required is to register your model in the admin site:

The philosophy here is that your site is edited by a staff, or a client, or maybe just you – and you don’t want to have to deal with creating backend interfaces only to manage content.

One typical workflow in creating Django apps is to create models and get the admin sites up and running as fast as possible, so your staff (or clients) can start populating data. Then, develop the way data is presented to the public.
"""
# mysite/news/models.py
from django.db import models
from django.contrib import admin


class Reporter(models.Model):
    full_name = models.CharField(max_length=70)

    def __str__(self):
        return self.full_name


class Article(models.Model):
    pub_date = models.DateField()
    headline = models.CharField(max_length=200)
    content = models.TextField()
    reporter = models.ForeignKey(Reporter, on_delete=models.CASCADE)


# mysite/news/admin.py
admin.site.register(models.Article)
