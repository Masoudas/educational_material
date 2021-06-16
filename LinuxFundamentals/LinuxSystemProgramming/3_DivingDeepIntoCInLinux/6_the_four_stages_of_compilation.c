/**
 * We're basically aware of the four stages of compilation:
 * 	-	Preprocessing: Replacing definitions and macros and expansions.
 * 	-	Compilation: Converting our code to assembly language.
 * 	-	Assembling:	Converting assemply code into machine code, or object files.
 * 	-	Linkeage: Linking missing parts of the program.
 * 
 * To preprocess a file, we know that we need to use the -E and -P options, and conventionally we give the .i
 * extension to files:
 *  $ gcc -E -P prog.c	-o prog.i
 * 
 * To compile only, we give the -S option, and we give the optional .s extension:
 * $ gcc -S prog.c -o prog.s
 * 
 * To assemble (and compile,) we pass the -c option. Note that because assembly is not possible without compilation
 * first, the two steps are combined in one flag, but we have -S for just generating the compilation result:
 * 
 * $ gcc -c prog.s -o prog.o 
 * 
 * To link, we give no option, and just pass in our files:
 * $ gcc prog.o -o prog
 * 
 * Note that if a couple of object files are in the same folder, linker path by default contains the current 
 * folder, so we needn't specify any paths for the linker:
 * 
 * $ gcc prog1.o prog2.o -o prog
 * 
 * Finally, note that the naked gcc command as the above shows, does all the things, and generates the output
 * a.out file for us, which is essentially executable machine code.
 * 
 * Finally, recall that the file command can be used to determine the content of each file. Also don't forget
 * objdump for converting machine code to assembly compiled file.
 */