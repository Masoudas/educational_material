"""
A general temptation of mine is to await some kind of async function in the main context of my program. But this can't be done, because no event loops exist there.

Now, you may say I somehow create an event loop, an then I run my tasks. 
    -   First of all, there's no function for creating event loops.
    -   Event if you did it, tasks need to be run inside the loop. I haven't still seen a way of attaching them to the loop. So, no, this can't be done right now.
"""
import asyncio


async def nested():
    return 42

eventLoop = asyncio.new_event_loop()
task = asyncio.create_task(nested())

# This is an error! We're not inside an async environment to await something.
# await task
