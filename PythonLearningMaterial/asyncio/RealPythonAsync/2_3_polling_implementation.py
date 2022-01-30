"""
If you used polling, then you could change things up so that multiple tasks are completed. In this approach, the parent would periodically break away from the current task and check to see if any other tasks need attention.

Let’s make the polling interval something like fifteen minutes. Now, every fifteen minutes your parent checks to see if the washer, dryer or kids need any attention. If not, then the parent can go back to work on the checkbook. However, if any of those tasks do need attention, then the parent will take care of it before going back to the checkbook. This cycle continues on until the next timeout out of the polling loop.

This approach works as well since multiple tasks are getting attention. However, there are a couple of problems:

    -   The parent may spend a lot of time checking on things that don’t need attention: The washer and dryer haven’t yet finished, and the kids don’t need any attention unless something unexpected happens.

    -   The parent may miss completed tasks that do need attention: For instance, if the washer finished its cycle at the beginning of the polling interval, then it wouldn’t get any attention for up to fifteen minutes! What’s more, watching the kids is supposedly the highest priority task. They couldn’t tolerate fifteen minutes with no attention when something might be going drastically wrong.

You could address these issues by shortening the polling interval, but now your parent (the CPU) would be spending more time context switching between tasks. This is when you start to hit a point of diminishing returns.
"""
