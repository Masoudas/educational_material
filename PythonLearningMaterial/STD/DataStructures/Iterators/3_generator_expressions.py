"""
Some simple generators can be coded succinctly as expressions using a syntax similar to list comprehensions but with 
parentheses instead of square brackets. These expressions are designed for situations where the generator is used 
right away by an enclosing function. Generator expressions are more compact but less versatile than full generator 
definitions and tend to be more memory friendly than equivalent list comprehensions.
"""

sum(i*i for i in range(10))                 # sum of squares
285

xvec = [10, 20, 30]
yvec = [7, 5, 3]
sum(x*y for x,y in zip(xvec, yvec))         # dot product
260

page = """This is the first line.
This is the second line.
"""
unique_words = set(word for line in page.splitlines() for word in line.split())
print(unique_words)

unique_words = set(word for line in open("text") for word in line.split())	# Assuming we have a file


#valedictorian = max((student.gpa, student.name) for student in graduates)

data = 'golf'
list(data[i] for i in range(len(data)-1, -1, -1))