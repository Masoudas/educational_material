#!/bin/bash
ls -lS --time-style=long-iso WorkingWithFiles_2 | awk ' BEGIN { 
		getline;	# Doing nothing with the first line. 
		getline;	# Read the following line(s)
		name=$8; size=$5 	#
	} 
	{
		print name " " size
		getline;
		name=$8; size=$5 

	}
	'
