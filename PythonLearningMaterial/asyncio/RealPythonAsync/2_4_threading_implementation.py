"""
“If I could only clone myself…” If you’re a parent, then you’ve probably had similar thoughts! Since you’re programming virtual parents, you can essentially do this by using threading. This is a mechanism that allows multiple sections of one program to run at the same time. Each section of code that runs independently is known as a thread, and all threads share the same memory space.

If you think of each task as a part of one program, then you can separate them and run them as threads. In other words, you can “clone” the parent, creating one instance for each task: watching the kids, monitoring the washer, monitoring the dryer, and balancing the checkbook. All of these “clones” are running independently.

This sounds like a pretty nice solution, but there are some issues here as well. One is that you’ll have to explicitly tell each parent instance what to do in your program. This can lead to some problems since all instances share everything in the program space.

For example, say that Parent A is monitoring the dryer. Parent A sees that the clothes are dry, so they take control of the dryer and begin unloading the clothes. At the same time, Parent B sees that the washer is done, so they take control of the washer and begin removing clothes. However, Parent B also needs to take control of the dryer so they can put the wet clothes inside. This can’t happen, because Parent A currently has control of the dryer.

After a short while, Parent A has finished unloading clothes. Now they want to take control of the washer and start moving clothes into the empty dryer. This can’t happen, either, because Parent B currently has control of the washer!

These two parents are now deadlocked. Both have control of their own resource and want control of the other resource. They’ll wait forever for the other parent instance to release control. As the programmer, you’d have to write code to work this situation out.

    Note: Threaded programs allow you to create multiple, parallel paths of execution that all share the same memory space. This is both an advantage and a disadvantage. Any memory shared between threads is subject to one or more threads trying to use the same shared memory at the same time. This can lead to data corruption, data read in an invalid state, and data that’s just messy in general.

    In threaded programming, the context switch happens under system control, not the programmer. The system controls when to switch contexts and when to give threads access to shared data, thereby changing the context of how the memory is being used. All of these kinds of problems are manageable in threaded code, but it’s difficult to get right, and hard to debug when it’s wrong.

Here’s another issue that might arise from threading. Suppose that a child gets hurt and needs to be taken to urgent care. Parent C has been assigned the task of watching over the kids, so they take the child right away. At the urgent care, Parent C needs to write a fairly large check to cover the cost of seeing the doctor.

Meanwhile, Parent D is at home working on the checkbook. They’re unaware of this large check being written, so they’re very surprised when the family checking account is suddenly overdrawn!

Remember, these two parent instances are working within the same program. The family checking account is a shared resource, so you’d have to work out a way for the child-watching parent to inform the checkbook-balancing parent. Otherwise, you’d need to provide some kind of locking mechanism so that the checkbook resource can only be used by one parent at a time, with updates.
"""
