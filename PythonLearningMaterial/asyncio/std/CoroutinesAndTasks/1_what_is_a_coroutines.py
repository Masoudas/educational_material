"""
Coroutines declared with the async/await syntax is the preferred way of writing asyncio applications. For example, the following snippet of code (requires Python 3.7+) prints “hello”, waits 1 second, and then prints “world”:

Important In this documentation the term “coroutine” can be used for two closely related concepts:
a coroutine function: an async def function;

a coroutine object: an object returned by calling a coroutine function.

Note that simply calling a coroutine will not schedule it to be executed:

>>> main()
<coroutine object main at 0x1053bb7c8>

"""
import asyncio


async def main():
    print('hello')
    await asyncio.sleep(1)
    print('world')

asyncio.run(main())
# hello
# world
