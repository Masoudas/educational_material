"""
To actually run a coroutine, asyncio provides three main mechanisms:

    -   The asyncio.run() function to run the top-level entry point “main()” function (see the above example.)
    -   Awaiting on a coroutine. The following snippet of code will print “hello” after waiting for 1 second, and then print “world” after waiting for another 2 seconds:

Me: Notice that in this execution, the first say_after is executed, and we await its response, and once that's finished, we move on to the exection of the second one. So, this execution is in fact sequential, and not concurrent. We can of course make it concurrent, using the gather function, which we talk about next.
"""
import asyncio
import time


async def say_after(delay, what):
    await asyncio.sleep(delay)
    print(what)


async def main():
    print(f"started at {time.strftime('%X')}")

    await say_after(1, 'hello')
    await say_after(1, 'world')

    print(f"finished at {time.strftime('%X')}")

    # Execution concurrently. Notice that this time around, world is going to be executed first.
    # Think about why do we have to use the await keyword here?
    # await asyncio.gather(say_after(1, 'hello'), say_after(0.5, 'world'))

asyncio.run(main())
