"""
Coroutines
Python coroutines are awaitables and therefore can be awaited from other coroutines:

Me: What happens here? Well, there's an async function, which does not have any awaitables in it. The point is that this async function must be executed asynchronously in another thread. Now, my question is, how are we to call nonasynchronous function asyncly? The answer is (abo tai!) that we probably have to wrap it in an asynchronous function. Notice also the use of await in the nested cal below.

Me: What is the point of await? It seems sometimes it returns back the execution to scheduler (pr whatever,) when we call it with sleep, and other times it creates a new thread for the async task.
"""

import asyncio


async def nested():
    return 42


async def main():
    # Nothing happens if we just call "nested()".
    # A coroutine object is created but not awaited,
    # so it *won't run at all*.
    nested()

    # Let's do it differently now and await it:
    print(await nested())  # will print "42".

asyncio.run(main())
