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
 */