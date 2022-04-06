"""
So, how do we run async operations together in parallel?

The answer is simple, we use the gather function to run async operations together, and as such, we wait only for the longest operation to finish. Cool.

As such, we can see that the sequence of execution becomes like this:
#####
Connecting Hue Light.
Connecting to Smart Speaker.
Connecting to Smart Toilet.
Smart Speaker connected.
Smart Toilet connected.
Hue Light connected.
##### Takes 2 seconds

As such, each future that completes first is returned first, and then Hue Light which is the longest is returned last. So, sequential operations become parallel, and take as much as the longest operation. This is just done using the gather function.

But notice again that that we await the results of gather. If we're writing an application that does not to await for a response, then we simply use gather, and move on from it. Otherwise, we need to await the response. As such, a parallelization occurs, and we needn't for responses

"""