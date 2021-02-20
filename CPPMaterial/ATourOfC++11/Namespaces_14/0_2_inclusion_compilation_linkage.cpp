/** This is me:
* We want to further discuss why we need to put guards for header files.
* 
* Before we start, we should point out that we can repeat the declaration of functions and classes.
* However, we can't provide two defintions for them.
* 
* A second point to remember is that header files are not explicitly turned into machine codes during
* compilation (no object file corresponds to a header file). They are only there to be replaced in the
* beginning of a file. To examine this, put a main inside a header file and see that it does not compile.
* 
* A third point is that when an object is used, the linker will search for it inside the object files. There
* are two points two note here:
* 1-	There can be no repetitive objects inside the linker, or linker will fail.
* 2-	There's one thing trying to solve the linkage problem, a whole other thing is to declare something when
*	writing a code. Say I want to use a function 'f'. Even though it may be available in some object file, I still
*	need to declare it as a function somewhere, or I get a wiggly thing and my code wouldn't compile.
* 
* I think now, it's obvious why we need header files. Header files provide a unified way of defining a declaration
* all around the code for us.
* 
* Consider this: Say we define a function 'void f()' in a .cpp file. This would turn into an object file. Now, I can use
* it everywhere else by just writing the declaration 'void f()' on top of the file. Then:
* 1-	This code would compile, because f is declared.
* 2-	Linkage is fine, because the 'f' is defined in a proper object file.
* 
* Cool! However, this method is error prone, as we may mess up the declaration of f.
* This is the reason why we include headers, rather than including the actual source file. When we include,
* we resolve the compilation problem of declaration. Then linkage to the actual file is resolved by the linker.
* 
* A fourth point is that even though we may structure our project into several subfolders, the VS compiler 
* (at least) creates a pool of object files, all of which on the same path, and then tries to link them 
* together. It appears to make sense, because the linker should not be bothered with searching for paths, etc.
* Hence, how you order your project is just a matter of taste, and does not affect linkage (just compilation).
* Hence, inclusion of path is just a matter of compilation.
* 
* A fifth point is that repetitive declarations is no problem for us. Say h1.hpp declares f, and h2.hpp
* repeats its declaration (either by inclusion of h1, or it just plainly rewrites f). It's no problem! So long
* as we don't provide a repetitive definition of f, we're fine! The reason why we guard the headers is to avoid
* double definition. Double declaration is Ok!
* 
* Ok. So now, let's play with these concepts with some examples:
* 
* %%%%%%%%%%%%%%%%%%%% Example 1:
* h1.hpp:
* #define INCLUSION
* 
* h2.hpp
* #include "h1.hpp"
* #ifdef INCLUSION
* // Do something here
* 
* Now perhaps, I wanted to use INCLUSION for some other purpose. But now that it's defined by the included
* header, the purpose is defeated. 
* 
* %%%%%%%%%%%%%%%%%%%% Example 2:
* As another example, conside this:
* -- h1.hpp:
* void f(){}	// Defined f here. For now, it's no problem, because a header file is not directly turned into
*				// an object.
*
* -- h2.hpp
* #include "h1.hpp" // Ok. Definition of f is repeated, but we've not inlcuded the header. No object file!
* 
* -- main.cpp
* void f(){}
* 
* int main(){f();}	// Fine, we only have one definition of f!
* 
* %%%%%%%%%%%%%%%%%%%% Example 3:
* Consider h1 and h2 of the previous example
* 
* -- f.cpp
* #include "h1.hpp"	// Now f is turned an object in f.obj.
* 
* -- main.cpp
* void f();	// Notice that this is just a declaration!
* int main(){f();}	// Fine. Declaration is there, and linkage finds f.
* 
* 
* %%%%%%%%%%%%%%%%%%%% Example 4:
* Consider h1, h2 and f.cpp of the previous example:
*
* -- main.cpp
* #include "h1.hpp"	// Oops! Now, the object f is defined in two files! Linkage error.
* 
* 
* %%%%%%%%%%%%%%%%%%%% Example 5:
* Consider h1, h2 and f.cpp of the previous example:
*
* -- main.cpp
* void f(){}	// Oops. Two definitions of f
* 
* 
* %%%%%%%%%%%%%%%%%%%% Example 6:
* -- h1.hpp:
* void f();	// Declare f here
*
* -- f.cpp
* void f(){}	// Notice that there's no header here! f.obj will have f().
* 
* -- main.cpp
* void f();		// Simple declaration.
* int main(){
*	f();	// Fine. This will be linked to the f of obj.
* }
* 
* %%%%%%%%%%%%%%%%%%%% Example 7:
* -- deep/h1.hpp:
* void f();	// Declare f here
*
* -- deep/f.cpp
* void f(){}	// Notice that there's no header here! f.obj will have f().
* 
* -- main.cpp
* void f();		// Simple declaration.
* int main(){
*	f();	// Again fine. Why? All object files are pooled together, and linker finds f.
* }
* This example shows that we should never have repeated names in a namespace!
* 
* %%%%%%%%%%%%%%%%%%%%
* 
* As a final point, if we provide two implementation in two different files, someone detects it, and that 
* someone is the linker. I think because linker is trying to make a table of all the objects, and sees the
* duplication! So this is in fact good news!
* 
* Here's a question: Wouldn't it make more sense to provide a guard for the function body, rather than
* it's header? No. Because we never include the implementation.
* 
* As another side note, we can see why even providing different name for every function or class in the code
* base does not resolve the above problem. Even if all function names are unique, a function body may be 
* repeated through the parent, child, grandchild scheme, duplicating the function body definition.
*
*/

void my_f();
void my_f();

class my_class;
class my_class;

void my_f() {

}

//void my_f() { Error. Repeated function body.
//	int x = 10;
//}


//int main() {
//	my_f();
//}