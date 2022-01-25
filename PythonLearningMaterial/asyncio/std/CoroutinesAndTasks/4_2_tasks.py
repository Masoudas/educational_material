"""
    -   asyncio.create_task(coro, *, name=None)

Wrap the coro coroutine into a Task and schedule its execution. Return the Task object.
If name is not None, it is set as the name of the task using Task.set_name().

The task is executed in the loop returned by get_running_loop(), RuntimeError is raised if there is no running loop in current thread. This function has been added in Python 3.7. Prior to Python 3.7, the low-level asyncio.ensure_future() function can be used instead:

Me: What does it mean? It means we have to create tasks in an environment where there's an event loop. It implies inside an async function as far as I can tell.


async def coro():
    ...

# In Python 3.7+
task = asyncio.create_task(coro())
...

# This works in all Python versions but is less readable
task = asyncio.ensure_future(coro())
"""
# The example is all me:
import asyncio


async def nested():
    return 42


async def main():
    # Scenario I: Creating tasks inside a non async function
    task = asyncio.create_task(nested())
    await task

asyncio.run(main())
