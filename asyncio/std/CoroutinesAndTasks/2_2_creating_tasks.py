"""
The asyncio.create_task() function to run coroutines concurrently as asyncio Tasks.

Let’s modify the above example and run two say_after coroutines concurrently:

Me: Notice that we await the completion of the tasks. The difference is that the tasks are like creating a simple thread, and they start execution as soon as we define them. We can check that the tasks are being executed concurrently, by setting the waiting time of world to 0.5. The point, however, is that we always have to wait for async stuff to finish.

Me: What are tasks good for? For one thing, we can check that they're finished or not, or we can cancel them for example, etc.
"""
import asyncio
import time


async def say_after(delay, what):
    await asyncio.sleep(delay)
    print(what)


async def main():
    task1 = asyncio.create_task(
        say_after(1, 'hello'))

    task2 = asyncio.create_task(
        say_after(0.5, 'world'))

    print(f"started at {time.strftime('%X')}")

    # Wait until both tasks are completed (should take
    # around 2 seconds.)
    await task1
    await task2

    print(f"finished at {time.strftime('%X')}")

asyncio.run(main())
