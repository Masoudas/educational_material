/**
 * As we saw in the preceding sections, the stack together with the CPU registers define a task. As mentioned 
 * earlier, this stack consists of stack frames, each of which defines the (local) variables, parameters, data, 
 * and instructions for that particular instance of task execution. Of note is that although the stack and 
 * stack frames are primarily a software concept, it is an essential feature of any modern OS, with hardware 
 * support in many CPU instruction sets. Graphically, it can be be visualized like Fig4.
 * 
 * When using a debugger with one's C++ application, this is basically what one sees when requesting the 
 * backtrack--the individual frames of the stack showing the initial stack frame leading up until the current 
 * frame. Here, one can examine each individual frame's details.
 * 
 * Note: Stack is always in RAM. There is a stack pointer that is kept in a register in CPU that points to 
 * the top of stack, i.e., the address of the location at the top of stack. From Wiki: The stack area 
 * contains the program stack, a LIFO structure, typically located in the higher parts of memory (me hence,
 * the memory registeries of CPU are used for keeping such data, not for keeping the actuall stack. Although
 * some data is also loaded in cache!)
 */