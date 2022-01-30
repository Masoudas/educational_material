"""
    -   awaitable asyncio.gather(*aws, return_exceptions=False)
Run awaitable objects in the aws sequence concurrently. If any awaitable in aws is a coroutine, it is automatically scheduled as a Task.

If all awaitables are completed successfully, the result is an aggregate list of returned values. The order of result values corresponds to the order of awaitables in aws (ME: A natural one to one order between functions and the returned value of gather, which is a vector).

If return_exceptions is False (default), the first raised exception is immediately propagated to the task that awaits on gather(). Other awaitables in the aws sequence won’t be cancelled and will continue to run.

If return_exceptions is True, exceptions are treated the same as successful results, and aggregated in the result list.

If gather() is cancelled, all submitted awaitables (that have not completed yet) are also cancelled.

If any Task or Future from the aws sequence is cancelled, it is treated as if it raised CancelledError – the gather() call is not cancelled in this case. This is to prevent the cancellation of one submitted Task/Future to cause other Tasks/Futures to be cancelled.

Note: Deprecated since version 3.8, removed in version 3.10: The loop parameter. This function has been implicitly getting the current running loop since 3.7. See What’s New in 3.10’s Removed section for more information.
"""
import asyncio


async def factorial(name, number):
    f = 1
    for i in range(2, number + 1):
        print(f"Task {name}: Compute factorial({number}), currently i={i}...")
        await asyncio.sleep(1)
        f *= i
    print(f"Task {name}: factorial({number}) = {f}")
    return f


async def main():
    # Schedule three calls *concurrently*:
    # Me: I don't think we have to wait here.
    L = await asyncio.gather(
        factorial("A", 2),
        factorial("B", 3),
        factorial("C", 4),
    )
    print(L)


asyncio.run(main())
