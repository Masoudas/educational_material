for file in `find . "*" -type f -print`
do
	md5sum $file # Notice the use of $ to send the new process to background
done