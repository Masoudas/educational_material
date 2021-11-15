"""
In this example, we first read from a port (which would simulate server) the content created on a webpage. Then,
we process the messages. In this script, we only print the messages read from the port. But in the next script,
we convert them 
"""

import asyncio
import websockets

async def handle_connection(websocket, path):
    async for message in websocket:
        print(message)

if __name__ == "__main__":
    future = websockets.serve(handle_connection, "localhost", 8000)
    asyncio.get_event_loop().run_until_complete(future)
    asyncio.get_event_loop().run_forever()

