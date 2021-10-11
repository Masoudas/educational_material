"""
The following is an example of exception handling. Note that several exceptions are allowed.
"""
while True:
	try:
		x = int(input("Please enter a number: "))
		break
	
	except ValueError:
		print("Oops!  That was no valid number.  Try again...")
	
	except ZeroDivisionError:
		print("Ooopsy")

	finally:
		print("Finall statement.")