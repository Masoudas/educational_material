"""
Of course, we can do this a lot simpler. But, we're going to load a config file (as an ini file), that would contain all the information regarding configuration. 

One thing to recall is that topics need only be created, and our producer code here shall fill it. The following example demonstrates this.

ME: What are the arguments in 'delivery_callback'? The first one is the error generated, the second one is the message (event) we were trying to write to the topic.

ME: Note that each message has a key and a value, both of which are binaries. If so, then, how do we wrote key value pairs as message? The answer is simple. We convert a dictionary to a (string) then binary (like we normally do for jsons to write them to file) and then dump this as value. Notice again that keys have the same property.

ME: Who sets the timestamp of messages here? The answer is (Abo tai), it's set by default in the producer.produce. These can be seen in the documenation of this method:

# produce(topic[, value][, key][, partition][, on_delivery][, timestamp][, headers])

As we can see, we may also set headers in this method as well. One thing to note is that header key value pairs are stored in the following format. Imgine for example defining the header as follows:

'{"hello": "world"}'

Then, what is written to the message is as follows:
[
  {
    "key": "hello",
    "stringValue": "world"
  }
]

As such, we can see that headers would be a list of key value jsons. We can also set timestamps as well. But it should be noted that the timestamp has to be an integer value. As such why bother?!

"""
from random import choice
from configparser import ConfigParser
from confluent_kafka import Producer
import json

config_parser = ConfigParser()
with open("confluentClient/getting_started_with_confluent_client/setup.ini", "r") as f:
    config_parser.read_file(f)
config = dict(config_parser['default'])

# Create Producer instance
producer = Producer(config)

# Optional per-message delivery callback (triggered by poll() or flush())
# when a message has been successfully delivered or permanently
# failed delivery (after retries).


def delivery_callback(err, msg):
    if err:
        print('ERROR: Message failed delivery: {}'.format(err))
    else:
        print("Produced event to topic {topic}: key = {key:12} value = {value:12}".format(
            topic=msg.topic(), key=msg.key().decode('utf-8'), value=msg.value().decode('utf-8')))


# Produce data by selecting random values from these lists.
topic = "purchases"
user_ids = ['eabara', 'jsmith', 'sgarcia',
            'jbernard', 'htanaka', 'awalther']
products = ['book', 'alarm clock', 't-shirts', 'gift card',
            json.dumps({'batteries': "included"}).encode()]

count = 0
for _ in range(10):

    user_id = choice(user_ids)
    product = choice(products)
    producer.produce(
        topic, product, user_id, callback=delivery_callback, headers={
            "hello": "world"},
        timestamp="now")
    count += 1

# Block until the messages are sent.
producer.poll(10000)
producer.flush()
