"""
Let’s pretend we’ve decided to start a lucrative website, PyHats.com, that sells outrageously overpriced hats to anyone who will buy them, and hired you to build the site.

You’ll use Redis to handle some of the product catalog, inventorying, and bot traffic detection for PyHats.com.

It’s day one for the site, and we’re going to be selling three limited-edition hats. Each hat gets held in a Redis hash of field-value pairs, and the hash has a key that is a prefixed random integer , such as hat:56854717. Using the hat: prefix is Redis convention for creating a sort of namespace within a Redis database:

Notice that we use a pipeline to write to the database, which reduces the number of roundtrips to redis. Notice that once working with the pipeline is finished, we must call bgsave. At the same time, don't forget about pipe.execute.
"""
import random
import redis

random.seed(444)

hats = {
    f"hat:{random.getrandbits(32)}": i for i in
    (
        {
            "color": "black",
            "price": 49.99,
            "style": "fitted",
            "quantity": 1000,
            "npurchased": 0,
        },
        {
            "color": "maroon",
            "price": 59.99,
            "style": "hipster",
            "quantity": 500,
            "npurchased": 0,
        },
        {
            "color": "green",
            "price": 99.99,
            "style": "baseball",
            "quantity": 200,
            "npurchased": 0,
        })
}

r = redis.Redis(db=1)
with r.pipeline() as pipe:
    for h_id, hat in hats.items():
        pipe.hmset(h_id, hat)

    pipe.execute()

r.bgsave()
