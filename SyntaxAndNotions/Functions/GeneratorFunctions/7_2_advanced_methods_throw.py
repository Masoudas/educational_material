"""
We can also throw inside the generator function from the outside, which I guess is useful in concurrency.
"""
def infinite():
    num = 0
    while True:
        if not num%10:
            i = (yield num)
            if i is not None:
                num = i
        num += 1
		
pal_gen = infinite()
for i in pal_gen:
    print(i)
    digits = len(str(i))
    if digits == 5:
        pal_gen.throw(ValueError("We don't like large palindromes"))
    pal_gen.send(10 ** (digits))