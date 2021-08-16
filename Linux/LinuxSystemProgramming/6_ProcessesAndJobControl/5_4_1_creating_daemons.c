/**
 * A daemon is a background process that runs on the system and performs some tasks. 
 * 
 * The essential point in creatin a daemon is to create a process that has no parent other than systemd, and to
 * also change its session id, so that it wouldn't be killed by its session id (could be a terminal or log 
 * session.)
 * 
 * So, here are the steps we need to take:
 * 	-	Create an orphan
 * 	-	Set a new session in the child process (using setsid()).
 *  -	Fork the process again, to create a new child process. As such, we won't have a session leader, and it
 * 		won't obtain a controlling terminal (which our previous process had, because it was created in a terminal). 
 * 		Once again, we exit the parent process.
 * 	-	Set the umask of the child process to something sensible (umask sets the default file creation mode for
 * 		subsequent executions. For example umask(022)), mea.
 * 	-	We change the pwd to "/", so that this daemon wouldn't stop file systems from unmounting, or folders from
 * 		getting deleted (Say what?)
 * 	- 	Because this daemon is detached from a terminal, keeping stdin, stdout or stderr is pointless. Therefore,
 * 		we close their file streams using fclose. This is important because otherwise writing to them might cause
 * 		a crash.
 * 	-	Because other programs might use these file descriptors to write to them or read, we need to reopen 
 * 		file descriptors 0, 1, 2. Note that just opening anything with a descriptor would be fine, because
 * 		the indexing by default starts from 0 if no other file descriptors exist (so we should be cautious not
 * 		to have any other opened.) What should we open then? Well, we can open /dev/null.
 * -	We can also write to a file by openning it, as the logging action of our daemon.
 * 
 */