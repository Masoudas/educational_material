"""
First of all, there's a configuration document in the following link, which is useful:
See https://github.com/edenhill/librdkafka/blob/master/CONFIGURATION.md

ME: From among the parameters, we chose what we see in the config, and it seems to work fine.

ME: One thing to note is that messages are received one at a time. What I'm saying is that we're not getting an array of messaging all at once.

ME: What is the point of 'reset_offset' function? For every partition, we go to the start of the offset (meaning 'OFFSET_BEGINNING'.) As such, one has to ask, would I need to keep the last read offset? The answer is definitely yes.

ME: Notice the poll loop, where we wait to receive messages. If we find nothing in that loop, then the loop is repeated.

"""
from confluent_kafka import Consumer, OFFSET_BEGINNING


config = {
    'bootstrap.servers': "localhost:9092",
    'group.id': "python_example_group_1",
    'auto.offset.reset': 'smallest'}

# Create Consumer instance
consumer = Consumer(config)


def reset_offset(consumer, partitions):
    for p in partitions:
        p.offset = OFFSET_BEGINNING
    consumer.assign(partitions)


# Subscribe to topic
topic = "purchases"
consumer.subscribe([topic], on_assign=reset_offset)

# Poll for new messages from Kafka and print them.
try:
    while True:
        msg = consumer.poll(1.0)
        if msg is None:
            # Initial message consumption may take up to
            # `session.timeout.ms` for the consumer group to
            # rebalance and start consuming
            print("Waiting...")

        elif msg.error():
            print("ERROR: %s".format(msg.error()))

        else:
            # Extract the (optional) key and value, and print.

            print("Consumed event from topic {topic}: key = {key:12} value = {value:12}".format(
                topic=msg.topic(), key=msg.key().decode('utf-8'), value=msg.value().decode('utf-8')))

except KeyboardInterrupt:
    pass

finally:
    # Leave group and commit final offsets
    consumer.close()
