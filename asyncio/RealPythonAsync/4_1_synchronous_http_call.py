"""
The next version of the program is kind of a step forward as well as a step back. The program is doing some actual work with real IO by making HTTP requests to a list of URLs and getting the page contents. However, it’s doing so in a blocking (synchronous) manner.

The program has been modified to import the wonderful requests module to make the actual HTTP requests. Also, the queue now contains a list of URLs, rather than numbers. In addition, task() no longer increments a counter. Instead, requests gets the contents of a URL retrieved from the queue, and prints how long it took to do so.

Just like in earlier versions of the program, yield turns task() into a generator. It also performs a context switch that lets the other task instance run.

Each task gets a URL from the work queue, retrieves the contents of the page, and reports how long it took to get that content.

As before, yield allows both your tasks to run cooperatively. However, since this program is running synchronously, each session.get() call blocks the CPU until the page is retrieved. Note the total time it took to run the entire program at the end. This will be meaningful for the next example.
"""
import queue
import requests
from codetiming import Timer


def task(name, work_queue):
    timer = Timer(text=f"Task {name} elapsed time: {{:.1f}}")
    with requests.Session() as session:
        while not work_queue.empty():
            url = work_queue.get()
            print(f"Task {name} getting URL: {url}")
            timer.start()
            session.get(url)
            timer.stop()
            yield


def main():
    """
    This is the main entry point for the program
    """
    # Create the queue of work
    work_queue = queue.Queue()

    # Put some work in the queue
    for url in [
        "http://google.com",
        "http://yahoo.com",
        "http://linkedin.com",
        "http://apple.com",
        "http://microsoft.com",
        "http://facebook.com",
        "http://twitter.com",
    ]:
        work_queue.put(url)

    tasks = [task("One", work_queue), task("Two", work_queue)]

    # Run the tasks
    done = False
    with Timer(text="\nTotal elapsed time: {:.1f}"):
        while not done:
            for t in tasks:
                try:
                    next(t)
                except StopIteration:
                    tasks.remove(t)
                if len(tasks) == 0:
                    done = True


if __name__ == "__main__":
    main()
