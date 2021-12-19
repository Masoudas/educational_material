"""
Essentially, we have a series of devices that send us information. They are read sequentially, and that's it.

Recall the difference between a process and threads within that process:
    -   A process has independent memory allocated to it.
    -   Threads in a process work on the same memory.

OS schedules how much CPU each process gets.
"""