GCC := g++		# Defining variable.

OUTPUT := ch01_mt_example	
SOURCES := $(wildcard *.cpp)	# Use a wild card to access files.
CCFLAGS := -std=c++2a 	# g++ flags. Notice we're not saying lpthread here. 
LFLAGS := -lpthread	# Equivalently we could just write -pthread, like in gcc we just say -libc. Note that 
					# Lflags have to go to the end.

all: $(OUTPUT) # What we do when we write make all command. Output would be a rule.

# Definition of the rule is here. Apparently, the command has to be written after a tab, or we get an error!!
# I swear. So $(GCC) ... has to be written after a tab, or we get a "Makefile:11: *** missing separator.  Stop."
# error
$(OUTPUT): 	
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES) $(LFLAGS)

# What to do on the make clean command. Just remove the generated executable.
# I added the echo part for fun.
clean:
	rm $(OUTPUT)
	echo $(SOURCES)	

.PHONY: all	# When writing make all, execute the all command from here, not anything else.