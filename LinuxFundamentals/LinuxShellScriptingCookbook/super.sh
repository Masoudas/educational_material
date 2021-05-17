#!/bin/bash


no=1
ls + 2>errors 
result=`echo "$no * 1.5" | bc`
echo $result
