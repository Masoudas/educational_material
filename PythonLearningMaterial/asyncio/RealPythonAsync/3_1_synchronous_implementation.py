"""
This first example shows a somewhat contrived way of having a task retrieve work from a queue and process that work. A queue in Python is a nice FIFO (first in first out) data structure. It provides methods to put things in a queue and take them out again in the order they were inserted.

In this case, the work is to get a number from the queue and have a loop count up to that number. It prints to the console when the loop begins, and again to output the total. This program demonstrates one way for multiple synchronous tasks to process the work in a queue.

This shows that Task One does all the work. The while loop that Task One hits within task() consumes all the work on the queue and processes it. When that loop exits, Task Two gets a chance to run. However, it finds that the queue is empty, so Task Two prints a statement that says it has nothing to do and then exits. There's nothing in the code to allow both Task One and Task Two to switch contexts and work together.
"""

import queue


def task(name, work_queue):
    if work_queue.empty():
        print(f"Task {name} nothing to do")
    else:
        while not work_queue.empty():
            count = work_queue.get()
            total = 0
            print(f"Task {name} running")
            for x in range(count):
                total += 1
            print(f"Task {name} total: {total}")


def main():
    """
    This is the main entry point for the program
    """
    # Create the queue of work
    work_queue = queue.Queue()

    # Put some work in the queue
    for work in [15, 10, 5, 2]:
        work_queue.put(work)

    # Create some synchronous tasks
    tasks = [(task, "One", work_queue), (task, "Two", work_queue)]

    # Run the tasks
    for t, n, q in tasks:
        t(n, q)


if __name__ == "__main__":
    main()
