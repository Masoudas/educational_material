#!/bin/bash
ls -lS --time-style=long-iso WorkingWithFiles_2 | awk ' BEGIN { 
		getline;	# Doing nothing with the first line. 
		getline;	# Read the following line(s)
		name=$8; size=$5 	#
	} 
	{
		getline;
		name=$8; size=$5 
		"cat super.sh " | getline; s=$1;
		print s
	}
	'
