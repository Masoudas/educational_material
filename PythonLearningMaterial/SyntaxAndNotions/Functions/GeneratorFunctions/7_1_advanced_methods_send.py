"""
Consider the following function. Notice the 'i = (yield num)' expression. As we notice, yield is not an statement
but rather an expression. Defining it as an expression allows for manipulation, but it also allows us to send
a value back to the function. Wghy is there an if statement for if i is None? Because if this function is used
with the next method, then if the iterator throws, then i that is sent is None. 

In the main function, we'll see how to send values back to the function.

What you’ve created here is a coroutine, or a generator function into which you can pass data. These are useful 
for constructing data pipelines, but as you’ll see soon, they aren’t necessary for building them. 
"""

def infinite():
    num = 0
    while True:
        if not num%10:
            i = (yield num)
            if i is not None:
                num = i
        num += 1

infinity = infinite()
for i in infinity:
	print(i)
	digits = len(str(i))
	infinity.send(10 ** (digits))	# Sending a value back to the generator expression. Can't use the function
									# Name directly as it seems!