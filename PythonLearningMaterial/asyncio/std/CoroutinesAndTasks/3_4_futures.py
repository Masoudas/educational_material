"""
A Future is a special low-level awaitable object that represents an eventual result of an asynchronous operation.

When a Future object is awaited it means that the coroutine will wait until the Future is resolved in some other place.

Future objects in asyncio are needed to allow callback-based code to be used with async/await.Normally there is no need to create Future objects at the application level code. Future objects, sometimes exposed by libraries and some asyncio APIs, can be awaited:

async def main():
    await function_that_returns_a_future_object()

    # this is also valid:
    await asyncio.gather(
        function_that_returns_a_future_object(),
        some_python_coroutine()
    )
    
A good example of a low-level function that returns a Future object is loop.run_in_executor().

Me: Notice that even with gather, we have to await the execution of the coroutines inside the async function. So, what if I wanted to execute these two coroutines inside the function, and wait for their response in another place? I'll probably have to use tasks, and await their response there.

Me: Note that gather must wait to gather all the results, but the methods are executed concurrently. As such, whichever method finished first, that's the method whose response we receive first.
"""
# This is my example:
import asyncio


async def nested():
    print("Inside nested")
    return 42


async def printer():
    await asyncio.sleep(1)
    print("Hello!")


async def main():
    # Await the execution of coroutines
    futures = await asyncio.gather(nested(), printer())

    print(futures[0])   # Future tuple.

asyncio.run(main())
