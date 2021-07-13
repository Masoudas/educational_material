/** 
 * An example of a more elaborate make script that uses "area.c (has main) area.h, help.c, rectangle.c, 
 * circle.c" is given below. Note that except for CC and CFLAGS, all the other variables we define are just
 * our own conventions. Note that we write a receipe for the linkeage under area alone, and call the resulting binary
 * as area. Notice the DEPS variable. It tells about the header dependencies of the area object file. We include it
 * separately because there's no compilation command, in the line that says area.o: $(DEPS) to declare this header
 * dependency, without defining an actual compilation command.
 * 
 * Notice that we don't define a separate compilation command. Make will take care of it for us. 
 
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic
LIBS=-lm		
OBJS=area.o help.o rectangle.o triangle.o circle.o	# Object files corresponding to each file.
DEPS=area.h		
bindir=/usr/local/bin
area: $(OBJS)
	$(CC) -o area $(OBJS) $(LIBS)	
area.o: $(DEPS)
clean:
	rm area $(OBJS)
install: area
	install -g root -o root area $(bindir)/area
uninstall: $(bindir)/area
	rm $(bindir)/area

 * Notice that we've defined a clean command to remove all the object and binary files we generate. 
 * Notice that we've defined a dependency for the unistall command. This is there, so that only if the install folder 
 * exists, it will be deleted. However, we didn't define any dependency for the clean command, because if the user has
 * deleted some object files, we want to still be able to delete it. 
 */
 