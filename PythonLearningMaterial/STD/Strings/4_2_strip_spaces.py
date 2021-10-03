"""
To strip white spaces:
	-	From the beginning of a string: use lstrip. 
	-	From the end: 					use rstrip 
	-	Both beginning and end:			use strip.

Note: Essentially 'l' and 'r' as such should be considered left and right in all string methods.

Note that if other chars are given to the strip method argument, then those chars are removed from the beginning
or the end. These methods do not remove from the middle of the string. Also note that these methods remove as many
instances of the given string as exist from the beginning or the end, and they are repetetive. Hence, as many times
as for example "@#" exists in the beginning or the end is removed.

Note that always a copy of the string is returned.
"""
my_str = "			Has leading and trailing spaces.	"
print("Removing leading spaces: ", my_str.lstrip())
print("Removing leading and trailing spaces:", my_str.strip())


### Removing other chars from the beginning
regular_text = "$@G#This is a regular text."

clean_begin_text = regular_text.lstrip("#$@G")

print(regular_text)
#$@G#This is a regular text.

print(clean_begin_text)
#This is a regular text.
