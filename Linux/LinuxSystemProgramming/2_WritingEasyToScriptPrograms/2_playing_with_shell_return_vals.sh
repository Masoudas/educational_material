#!/bin/bash
<<comment
 In this script, we shall demonstrate how to return values from a script. For this end, we shall check the
 number of input arguments. Then, we shall check each one of them for existance as a file and if one of
 them does not exist, we return 1. Otherwise, we return 0.

 Note that returning actually is done using exit, and not return. Also notice how we loop over all the script
 arguments.

 So now, note that a script that returns the correct exit value can be used with && or || for example, to
 make nice snippets. This is because the return value is considered true in these commands.

 $ ./this_script / && echo "Phew, it exists!" || echo 'No, it's not there!'
 $ ./this_script /mama &> /dev/null; \
   if [ $? -eq 3 ]; then echo "That doesn't exist"; fi 

Finally, note that we put $@ inside a string. This is to ensure that if it contains a space, it will still
be considered as a complete string (why?).

I also bring your attention to the fact that $i, i=0,.. correspond to the arguments of main, and so does $#
to argc. This is why $0 returns the program name.

Like our C programs, we want our scripts to exit with a relevant return value (or exit code, as it is also 
called). We use exit to leave the script and set a return value. In case the user doesn't supply precisely one 
argument, we exit with code 1, a general error code. And if the script is executed as it should, and the file 
or directory exists, we exit with code 0. If the script is executed as it should, but the file or directory 
doesn't exist, we exit with code 3, which isn't reserved for a particular use, but still indicates an error 
(all non-zero codes are error codes). This way, other scripts can fetch the return value of our script and act 
upon it.
comment

if [ $# -le 0 ]; then
    echo "Not enough arguments"
    exit 1
fi


for filename in "$@"; do
    test ! -f ${filename} && exit 3     # Test if exists as file and if not, return
done

## A bizzare alternative from me!
for filename in {1..$#}; do
    echo "Here"
    eval "test ! -f '$'${filename}" && exit 3
done

exit 0




