/**
 * So far, we've seen how to spawn a process. That is, to create a new process inside an existing process. The
 * correct terminology is in fact forking. What's happening is that a process creates a copy of itself—it forks.
 * 
 * In the previous example, we changed the process executable. Here, the intend is to create a new child process
 * inside our current process and execute something inside of it. (Me: perhaps this is not that different from
 * creating a new thread. The point however is that we supply a new executable here, but there, a new section of
 * the code.)
 * 
 * The child process is identical to the parent process, except it has a new PID. Inside the parent process, 
 * fork() returns the PID of the child process. Inside the child process, 0 is returned. This is why the parent 
 * could print the PID of the child process. 
 * 
 * Note that both processes contain the same program code, and both processes are running, but only the specific 
 * parts in the if statements get executed, depending on whether the process is the parent or the child.
 * 
 * The program is given below. If we use pstree in another termina, we see that:

pstree -A -p -s PID_OF_EXECUTABLE	
systemd(1)---tmux(4050)---bash(18817)---forkdemo(21764)---forkdemo(21765)
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
   pid_t pid;
   printf("My PID is %d\n", getpid());
   /* fork, save the PID, and check for errors */
   if ( (pid = fork()) == -1 )
   { 
      perror("Can't fork");
      return 1;
   }

   if (pid == 0)
   {
      /* if pid is 0 we are in the child process */
      printf("Hello from the child process!\n");
      sleep(120);
   }
   else if(pid > 0)
   {
      /* if pid is greater than 0 we are in 
       * the parent */
      printf("Hello from the parent process! My child has PID %d\n", pid);
      sleep(120);
   }
   else
   {
      fprintf(stderr, "Something went wrong forking\n");
      return 1;
   }

   return 0;
}
