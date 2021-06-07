#!/bin/bash
#Filename: sleep.sh 

f(){
    echo "$@"
    echo "$*"
}

f 1 33 3 'a;' a

PS3="Choose case: "
select i in case1 case2 case3
do 
    case $i in
    case1) echo "Case1";;
    case2) echo "Case2";;
    case3) exit;;
    esac
done