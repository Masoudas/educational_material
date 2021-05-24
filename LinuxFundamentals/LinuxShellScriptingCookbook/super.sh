#!/bin/bash

if [ -e /  -a -r / -a ! -w / -a -x / -a -s / -a -d / -a ! -f / ]; then
    printf "Root exits, is readable, not writable, but executable (can be lsed), and its size is non zero"
    printf "\nand is a directory and not a file\n"
fi

if [ -u "super.sh" -a -g "super.sh" ]; then
    echo "The current file has its uid bit and its gid bits set"
fi