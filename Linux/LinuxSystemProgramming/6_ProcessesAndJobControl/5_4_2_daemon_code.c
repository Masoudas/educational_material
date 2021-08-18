/**
 * In what follows, we shall create a daemon, and as an added bonus, we create a log file inside this daemon and
 * write to a log file with it every 5 seconds.
 * 
 * Note that because we need to write to the /var folder, we need to start our daemon as superuser. So, we should:
 
 $ sudo ./program

 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

int main(void){ 
    pid_t pid;
    FILE *fp;
    time_t now; /* for the current time */
 
    const char* pidfile = "/var/run/my-daemon.pid";
    const char* daemonfile = "/tmp/my-daemon-is-alive.txt";
    
    if ( (pid = fork()) == -1 )
    {
       perror("Can't fork");
       return 1;
    }
    else if ( (pid != 0) )
    {
       exit(0);
    }
 
    /* the parent process has exited, so this is the child. create a new session to lose the 
     * controlling terminal */
    umask(022); /* set the umask to something ok */
    chdir("/"); /* change working directory to / */
    /* open the "daemonfile" for writing */
    if ( (fp = fopen(daemonfile, "w")) == NULL )
    {
       perror("Can't open daemonfile");
       return 1;
    }
    
    /* fork again, creating a grandchild, the actual daemon */
    if ( (pid = fork()) == -1 )
    {
       perror("Can't fork");
       return 1;
    }
    else if ( pid > 0 )	/* Some logging before parent of daemon exits */
    {
       /* open pid-file for writing and error 
        * check it */
       if ( (fp = fopen(pidfile, "w")) == NULL )
       {
          perror("Can't open file for writing");
          return 1;
       }
       /* write pid to file */
       fprintf(fp, "%d\n", pid); 
       fclose(fp); /* close the file pointer */
       exit(0);
    }
 
    /* from here, we don't need stdin, stdout or, stderr anymore, so let's close them all, then re-open them to 
    	  /dev/null */
    close(STDIN_FILENO); close(STDOUT_FILENO); close(STDERR_FILENO);
 
	 // ME: I decided to close the file streams as well, even though closing the descriptor maybe enough? In any
	 // case, I closed the file streams after file descriptors, because file descriptors may depend on file streams.
	 fclose(stderr); fclose(stdout); fclose(stderr);
   
    open("/dev/null", O_RDONLY); /* 0 = stdin */
    open("/dev/null", O_WRONLY); /* 1 = stdout */
    open("/dev/null", O_RDWR); /* 2 = stderr */
 
    for (;;)
    {
       time(&now);
       fprintf(fp, "Daemon alive at %s", ctime(&now));
       fflush(fp); /* flush the stream */
       sleep(30);
    }
    return 0;
}