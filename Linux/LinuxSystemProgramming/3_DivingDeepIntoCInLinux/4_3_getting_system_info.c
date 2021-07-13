/**
 * In the following example, we try and get various system information from the sys header. Most of these functions
 * are in the sysinfo header. In particular, we can fill an instance of sysinfo struct inside the sysinfo struct
 * to get many useful information.
 * 
 * A couple of notes:
 * 	-	getpwd returns the path to the present directory from which the code is executed.
 * 	-	Note that to get UID and other variables, we use the getenv function. The following functions returning
 * 		uid, euid etc are the ones returning THE CALLING PROCESS information.
 * 	-	effective uid is the id that's associated with commands like ping, where with the s field permission, we 
 * 		change the effective owner of the file to the executer, while the actual (real) owner is root. To understand
 * 		its effect, change owner to root, give the 4755 permission to the executable and execute it as root. You see 
 * 		that uid is 0 (root, the current owner of the file), but the effective owner of the process caller is
 * 		1000, which is me, who executed it.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>	// Doesn't seem necessary!


void unistdInfo(){
	fprintf(stdout, "-- Printing unistd (user) info --\n");

	char pwd[100];
	if (getcwd(pwd, sizeof pwd))
		fprintf(stdout, "The current working directory is: %s\n", pwd);

	fprintf(stdout, "The guid and effective guid are %i and %i\n", getgid(), getegid());
	fprintf(stdout, "The uid and effective uid are %i and %i\n", getuid(), geteuid());
	fprintf(stdout, "The current proccess id is: %i, and it's parent is %i\n", getpid(), getppid());
}

void getSystemInfo(){
	struct sysinfo si;

	sysinfo(&si);
	fprintf(stdout, "-- Printing system info --\n");
   	fprintf(stdout, "Time since boot is %li\n", si.uptime);	
	fprintf(stdout, "Your machine has %ld megabytes of total RAM\n", si.totalram / 1024  / 1024);
	fprintf(stdout, "Your machine has %ld megabytes of free RAM\n", si.freeram / 1024 / 1024);
	fprintf(stdout, "Currently, there are %d processes running\n", si.procs);
}

int main(){
	getSystemInfo();
	unistdInfo();
}
