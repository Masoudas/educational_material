#!/bin/bash
sort $1 -o f1 

sort $2 | diff f1 - > /dev/null	# Saves the creation of one file

result=$?
rm f1

if [ $result -ne 0 ]; then	
	exit 1
fi
exit 0;
