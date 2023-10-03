"""
An important part of this process is to get the information of the bootstrap server. How do we do this? Go to the cluster overview, and then in cluster setting, under broker ids, find the information. The problem, however, is that with docker, the port and host name is different than what appears in the configuration. As such, we must check the configuration of docker to find out our broker servers. For example, mine is implemented on ports 9092 of server (using normal docker-compose) configuration. However, confluent configuration shows it on port 29092!

With the default docker-compose, we can see that the following connection works.
"""
from confluent_kafka import Producer
import socket

conf = {'bootstrap.servers': "localhost:9092",
        'client.id': socket.gethostname()}

producer = Producer(conf)
