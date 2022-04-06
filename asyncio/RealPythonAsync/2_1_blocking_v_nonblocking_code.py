"""
Writing asynchronous programs requires that you think differently about programming. While this new way of thinking can be hard to wrap your head around, it’s also an interesting exercise. That’s because the real world is almost entirely asynchronous, and so is how you interact with it.

Imagine this: you’re a parent trying to do several things at once. You have to balance the checkbook, do the laundry, and keep an eye on the kids. Somehow, you’re able to do all of these things at the same time without even thinking about it! Let’s break it down:

    -   Balancing the checkbook is a synchronous task. One step follows another until it’s done. You’re doing all the work yourself.

    -   However, you can break away from the checkbook to do laundry. You unload the dryer, move clothes from the washer to the dryer, and start another load in the washer.
    Working with the washer and dryer is a synchronous task, but the bulk of the work happens after the washer and dryer are started. Once you’ve got them going, you can walk away and get back to the checkbook task. At this point, the washer and dryer tasks have become asynchronous. The washer and dryer will run independently until the buzzer goes off (notifying you that the task needs attention).

    -   Watching your kids is another asynchronous task. Once they are set up and playing, they can do so independently for the most part. This changes when someone needs attention, like when someone gets hungry or hurt. When one of your kids yells in alarm, you react. The kids are a long-running task with high priority. Watching them supersedes any other tasks you might be doing, like the checkbook or laundry.

These examples can help to illustrate the concepts of blocking and non-blocking code. Let’s think about this in programming terms. In this example, you’re like the CPU. While you’re moving the laundry around, you (the CPU) are busy and blocked from doing other work, like balancing the checkbook. But that’s okay because the task is relatively quick.

On the other hand, starting the washer and dryer does not block you from performing other tasks. It’s an asynchronous function because you don’t have to wait for it to finish. Once it’s started, you can go back to something else. This is called a context switch: the context of what you’re doing has changed, and the machine’s buzzer will notify you sometime in the future when the laundry task is complete.

As a human, this is how you work all the time. You naturally juggle multiple things at once, often without thinking about it. As a developer, the trick is how to translate this kind of behavior into code that does the same kind of thing.
"""