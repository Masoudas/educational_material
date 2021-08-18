#!/bin/bash
<< 'comment'
This is me:

To create a daemon in shell, we can use the setsid function, which essentially forks the current process and creates
a new session. Note that there's an option to attach the new forked process to the current terminal, but that's
not what we want.

Also note that I found it simpler to just execute a new script with setsid, by defining my daemon processes inside
a new script. This is mostly because that's how setsid is used.

Note that the difference between this method and the one we discussed in the C code is that here, we first create
a bash to execute our daemon script. This is not a propery of the setsid command, but rather a self inflicting wound.
That is, if I implement the following command, we won't create that extra bash. The bash is created because we pass
./daemon_tasks as an argument:

$ setsid -f true && { while true; do sleep 10; echo "log from daemon at $(date)" >> /tmp/daemon-log.txrt; done; } &
Note that when using like this, we seem to need to send the process to background. Note also that I used the usuall
&& command to just be able to execute a while loop in the command. Otherwise, right now I can't think of a way to
write a while loop and pass it to a command without the brackets.
comment

echo "PID of the parent process is " $$ 
echo "Fork, and set sid by sending the process to the background:"

chmod 755 daemon_tasks.sh
#setsid -f ./daemon_tasks.sh 

echo "The parent process terminates here."

# setsid -f true && { while true; do sleep 10; echo "log from daemon at $(date)" >> /tmp/daemon-log.txrt; done; } &