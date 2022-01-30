"""
    -   coroutine asyncio.sleep(delay, result=None)

Block for delay seconds.
If result is provided, it is returned to the caller when the coroutine completes.

sleep() always suspends the current task, allowing other tasks to run.

Setting the delay to 0 provides an optimized path to allow other tasks to run. This can be used by long-running functions to avoid blocking the event loop for the full duration of the function call.

Deprecated since version 3.8, removed in version 3.10: The loop parameter. This function has been implicitly getting the current running loop since 3.7. See What’s New in 3.10’s Removed section for more information.

Example of coroutine displaying the current date every second for 5 seconds (ME: Note that the example is deprecated. The website says "Deprecated since version 3.8, removed in version 3.10: The loop parameter. This function has been implicitly getting the current running loop since 3.7. See What’s New in 3.10’s Removed section for more information"):

ME: Here's a thought. If I write "await asyncio.sleep" inside a function, do I create a new thread? Well, of course not. I stop the execution of that thread. The point I'm making, however, is that probably everytime I await something, I've created a new thread for it.
"""

import asyncio
import datetime


async def display_date():
    loop = asyncio.get_running_loop()
    end_time = loop.time() + 5.0    # Stop after loop creation time plus five seconds
    while True:
        print(datetime.datetime.now())
        if (loop.time() + 1.0) >= end_time:
            break
        await asyncio.sleep(1)

asyncio.run(display_date())
