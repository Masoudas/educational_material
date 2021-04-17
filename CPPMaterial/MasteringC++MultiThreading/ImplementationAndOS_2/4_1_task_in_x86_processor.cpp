/**
 * This discussion applies equally to 32 and 64 bit processors.
 * 
 * A task is defined as follows in the Intel IA-32 System Programming guide, Volume 3A:
 * 
 * "A task is a unit of work that a processor can dispatch, execute, and suspend. It can be used to execute 
 * a program, a task or process, an operating-system service utility, an interrupt or exception handler, or 
 * a kernel or executive utility." 
 * 
 * "The IA-32 architecture provides a mechanism for saving the state of a task, for dispatching tasks for 
 * execution, and for switching from one task to another. When operating in protected mode, all processor 
 * execution takes place from within a task. Even simple systems must define at least one task. More complex 
 * systems can use the processor's task management facilities to support multitasking applications."
 * 
 * This excerpt from the IA-32 (Intel x86) manual summarizes how the hardware supports and implements support 
 * for operating systems, processes, and the switching between these processes. 
 * 
 * It's important to realize here that, to the processor, there's no such thing as a process or thread. All 
 * it knows of are threads of execution, defined as a series of instructions. These instructions are loaded 
 * into memory somewhere, and the current position in these instructions is kept track of along with the 
 * variable data (variables) being created, as the application is executed within the data section of the 
 * process.
 * 
 * The book follows up with a detailed discussion here, the most important points of which are:
 *      [1] Each tasks runs in a hardware protected ring. We have Rings 0 to 3. Ring 0 is for OS, ring 3 for
 *          user processes, and 1 and 2 are not used.
 *      [2] There's a table structure for EACH task, called Task State Structure (TSS) (hence, for various
 *          threads, we have one of these tables.) These tables are fed to the cores to execute them. If we
 *          see the figures 2 and 3, we see that each of them have an address to the next task as well.
 *      [3] TTS is different, but quite similar for 32 and 64 bit processors.
 *      [4] ONLY 32 bit processes have hardware switching between tasks. However, most OS do the switching
 *          in software rather than hardware. Hence, 32 bits can switch from one table to another in HW.
 *      [5] The names that you see in the table (like for example SS0: The first stack segment selector field) 
 *          are registers and for example point to the top of the stack or etc. A famous one that we see all
 *          the time in assembly programs is the EAX, which is the output registery if I'm not mistaken.
 *      [6] In essence, this table is fed to the CPU and it will execute in one CPU cycle.
 * 
 * 
 */