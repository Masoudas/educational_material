#!/bin/bash
"""
This is all me:

In the following script, I shall try to immitate what I did with the C program in a shell script. The operator that
almost immitates forking in shell is the & operator.

To execute a set of commands in the forked process (namely, to immitate the execl command) I pass a shell function
to the forked process. This would be equivalent to executing a set of commands. I could have sent a shell script
(./commands &) to the background, but this is fine.

Note that when the process is forked, the rest of script that is in the foreground will continue. As such, we can
perfrom any additional tasks there. Moreover, I can use the $! to get the id of the background process.

What about variables? Well, note that the background because it's constructed from the parent process would have
all the variables of the parent process (just like any other process.) Over the Internet, they say that & is almost
equivalent to a fork!

As a side note, if I wanted to send the id of the child process to it, I could send it as a function argument.


"""

daemon_tasks(){
	while true; do
		echo "Shell-made daemon is alive at " $(date) >> "/tmp/my-daemon-is-alive.txt"
		sleep 10
	done
}

echo "PID of the parent process is " $$ 
echo "Fork, by sending the process to background:"

daemon_tasks &	# This process is (almost) forked and sent to background.
echo "The id of the forked process is: $!" 



