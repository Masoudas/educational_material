/**
 * By a zombie process, we mean a situation where the parent process does not wait on the child process. This
 * does not imply that the child process continues after the parent ends, but rather, the parent process does
 * not clean up the child process after it's terminated, by using the waitpid function. We could say that a
 * child process that has exited before the parent is a zombie process.
 * 
 * Why is this bad? It's because the child zombie process that has not been cleaned up stays in memory. It may
 * not necessarily use extra resources, and the process is idle, but because it occupies a PID, in extreme
 * situations all our PIDs may be occupied and we won't be able to create new ones! As such, zombies are different
 * from daemons.
 * 
 * Creating a zombie process is in fact rather easy, and we just don't wait for the child process with waitpid.
 * 
 * To actually check that a process is a zombie process, we can ps a | grep child_pid and see the result:

$ ps a | grep 20311
20311 pts/0    Z      0:00 [program] <defunct>
20467 pts/1    S+     0:00 grep --color=auto 20311
 
 * The Z in the status indicates that the process is zombie, and it's further verified by the <defunct> notion.
 * There are many details about child process and their state changes in the manual page for waitpid(). There's 
 * actually three wait() functions available in Linux. You can read about them all by using the man 2 wait 
 * command.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	__pid_t parent = getpid();
	fprintf(stdout, "PID of parent is %d\n", parent);

	__pid_t pid = 0;
	if ( (pid = fork()) == -1){
		perror("Can't create the process\n");
		return 1;
	}

	if (!pid){
		/* if pid is 0 we are in the child process */
      	printf("Hello and goodbye from the child!\n");    	
		exit(0);
	}
	else if (pid > 0){
      	/* if pid is greater than 0 we are in  the parent */
	    printf("Hello from the parent process! My child had PID %d\n", pid);
        sleep(120);
	
	} else{	 // Notice that the parent process does not wait for the child to terminate.
		fprintf(stderr, "Something went wrong with forking\n");
        return 1;
	}

}