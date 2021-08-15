     #!/bin/sh 
     # Filename: filestat.sh 

while read file; 
do
	echo $file
done <<< "This string is supplied"