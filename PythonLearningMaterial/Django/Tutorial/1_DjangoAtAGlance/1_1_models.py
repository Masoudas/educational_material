"""
Although you can use Django without a database, it comes with an object-relational mapper in which you describe your database layout in Python code.

The data-model syntax offers many rich ways of representing your models - so far, it's been solving many years' worth of database-schema problems. Here's a quick example.

Me: What is this useful for? Of course, for creating databases, not necessarily working with them, 

Now, we can create our databases.
$ python manage.py makemigrations
$ python manage.py migrate

The makemigrations command looks at all your available models and creates migrations for whichever tables don’t already exist. migrate runs the migrations and creates tables in your database, as well as optionally providing much richer schema control.

"""
# mysite/news/models
from django.db import models    # Models for modelling database


class Reporter(models.Model):
    full_name = models.CharField(max_length=70)

    def __str__(self):
        return self.full_name


class Article(models.Model):
    pub_date = models.DateField()
    headline = models.CharField(max_length=200)
    content = models.TextField()
    reporter = models.ForeignKey(Reporter, on_delete=models.CASCADE)

    def __str__(self):
        return self.headline
