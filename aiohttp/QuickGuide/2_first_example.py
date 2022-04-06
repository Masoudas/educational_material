"""
To access the get method, we need to create a client session first.

Notice that timeout raises TimeoutError, which the loop function reraise for us. We can then catch the timeout loop there.
"""
import aiohttp
import asyncio


async def main():
    url = "myurl.com"
    timeout = aiohttp.ClientTimeout(total=1)
    async with aiohttp.ClientSession(timeout=timeout) as session:
        async with session.get(url) as response:
            print("status:", response.status)
            print("headers:", response.headers)

            html = await response.json()
            #print("Body:", html, "...")

            return html

loop = asyncio.get_event_loop()
try:
    response = loop.run_until_complete(main())
    print(response['success'][2])

except asyncio.TimeoutError as e:
    print(e)
    print("Timeout error occurred")
