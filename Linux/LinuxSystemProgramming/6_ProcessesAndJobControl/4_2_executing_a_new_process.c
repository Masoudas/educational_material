/**
 * Thus far, we've only created a child process. Now, we want to execute a new program inside this forked process.
 * 
 * Me: Why wouldn't we just use execl directly? Note that execl replaces the executable in the thread completely.
 * However, we're creating a new process here.
 * 
 * So now, clearly what we can do is use execl to replace the executable of the new process. Again, like we 
 * discussed before, the child process executes the portion of the if loop with pid=0, and the current process
 * executes the part with pid > 0. Very cool! As such, we replace the current executable with a new one in the
 * child process.
 * 
 * Note that we needed to tell the parent process to wait for the child process with waitpid(). If we needed to 
 * run a program that didn't require a terminal, we could have done without waitpid(). However, we should always 
 * wait for the child process. If we don't, the child will end up as an orphan. In this particular case, especially
 * we're using a terminal for ls-pager, and we need to wait for this pid. When this process terminates, waitpid returns
 * the status of the child process to us as well.
 * 
 * Me: Why do we need this? Because if the parent process finishes before the child, then the child would have
 * no parents, which is not allowed in Linux (essentially!) Then, we'd an orphan child process. A process should
 * always have a parent.
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	__pid_t c_pid = getpid();
	fprintf(stdout, "pid of current process is: %i\n", c_pid);

	__pid_t pid;
	if ( (pid = fork() ) == -1){
		perror("Could not allocate new process");
		return 0;
	}

	if (pid  == 0){
		fprintf(stdout, "Inside the child process\n");

		if ( execl("/usr/bin/man", "man", "ls", (char*)NULL) == -1 )
      	{
      	   perror("Can't exec");
      	   return 1;
      	}
	} else if(pid > 0) {
      /* In the parent we must wait for the child to exit with waitpid(). Afterward, the
         child exit status is written to 'status' */
		int status;
    	waitpid(pid, &status, 0);
    	printf("Child executed with PID %d\n", pid);
    	printf("Its return status was %d\n", status);
   } else
   {
      fprintf(stderr, "Something went wrong with forking\n");
      return 1;
   }

	return 0;
}