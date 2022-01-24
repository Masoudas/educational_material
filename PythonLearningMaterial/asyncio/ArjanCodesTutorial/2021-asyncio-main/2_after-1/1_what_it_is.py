"""
We just add async to function, and it becomes async. This implies that we have to await it when we use it.

Notice that async has its own sleep function. The point is that right now, this code is still sequential, and we're not passing the async function still. Thus, we need to truly parallelize the code, so that connecting to each device is done in parallel.

Listen, async is async, meaning things are run not together (asynchronously.)

Notice that the execution of the program is still sequential, and we wait for every async operation to end, before moving on to the next in the main code (but they're done on different threads I guess).

Why do we need the await keyword? To wait for the function to finish. Otherwise, we just jump away from it. In fact, we can perfectly not wait for the process. But then, if we do so, the future is not returned, and we get some kind of coroutine error.

Notice that we await the sleep function of async as well.
"""