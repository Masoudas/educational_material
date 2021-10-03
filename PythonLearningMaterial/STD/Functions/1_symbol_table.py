"""
The execution of a function introduces a new symbol table used for the local variables of the function. More 
precisely, all variable assignments in a function store the value in the local symbol table; whereas variable 
references first look in the local symbol table, then in the local symbol tables of enclosing functions, then in 
the global symbol table, and finally in the table of built-in names. Thus, global variables and variables of 
enclosing functions cannot be directly assigned a value within a function (unless, for global variables, named 
in a global statement, or, for variables of enclosing functions, named in a nonlocal statement), although they 
may be referenced.

Me: Notice that we're talking about execution time here, which is what counts!

The actual parameters (arguments) to a function call are introduced in the local symbol table of the called 
function when it is called; thus, arguments are passed using call by value (where the value is always an object 
reference, not the value of the object). When a function calls another function, or calls itself recursively, a 
new local symbol table is created for that call.
"""