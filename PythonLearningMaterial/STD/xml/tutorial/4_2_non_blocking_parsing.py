"""
The downside of iterparse() is that it uses blocking calls to read the next chunk of data, which might be 
unsuitable for asynchronous code running on a single thread of execution. To alleviate that, you can look into 
XMLPullParser, which is a little bit more verbose:
"""

import xml.etree.ElementTree as ET

async def receive_data(url):
    """Download chunks of bytes from the URL asynchronously."""
    yield b"<svg "
    yield b"viewBox=\"-105 -100 210 270\""
    yield b"></svg>"

async def parse(url, events=None):
    parser = ET.XMLPullParser(events)
    async for chunk in receive_data(url):
        parser.feed(chunk)
        for event, element in parser.read_events():
            yield event, element