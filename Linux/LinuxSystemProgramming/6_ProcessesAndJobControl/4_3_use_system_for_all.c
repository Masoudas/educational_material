/**
 * Instead of using fork, execl and then waitpid to create the process, replace the executable and then wait
 * on it, we can use the system function directly to combine all three steps in one.
 * 
 * The man page says, the return value of system() is one of the following:
	-  If command is NULL, then a nonzero value if a shell is available, or 0 if no shell is available.
	-  If a child process could not be created, or its status could not be retrieved, the return value is -1 and 
	   errno is set to indicate the error.
	-  If a shell could not be executed in the child process, then the return value is as though the child shell 
	   terminated by calling _exit(2) with the status 127.
	-  If all system calls succeed, then the return value is the termination status of the child shell used to 
	   execute command. (The termination status of a shell is the termination status of the last command it 
	   executes.)
 * 
 * Notice however that creating a child process as such comes at a price. If we execute the pstree, we see that:
 
 $ pstree -A -p -s 957
systemd(1)---tmux(4050)---bash(957)---program(28274)---sh(28275)---man(28276)---pager(28287)

 * That is, to execute the passed command, the system command uses the execl together "sh -c" to execute the
 * passed command. Hence, an extra process is created. Again, the man page says system calls the following 
 * function:
 
 execl("/bin/sh", "sh", "-c", command, (char *) 0);
 * Notice also that we wait internally with waitpid as well.
 */

#include <stdlib.h>
#include <stdio.h>

int main(){
	int status;
	if ( (status = system("man ls")) == -1)
	{
      fprintf(stderr, "Error forking or reading status\n");
      return 1;
	}	

	return 0;
}