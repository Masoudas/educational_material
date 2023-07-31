"""
The first thing that we want to simulate is what happens when a user clicks Purchase. If the item is in stock, increase its npurchased by 1 and decrease its quantity (inventory) by 1. You can use .hincrby() to do this: (Me: hincrby is shorthand for h increase by. So, we can increase for both integer and float)
"""
import random
import redis

random.seed(444)

hats = {
    f"hat:{i}": i for i in
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


r.hincrby("hat:1", "quantity", -1)

r.hget("hat:1", "quantity")
# b'199'
r.hincrby("hat:1", "npurchased", 1)
