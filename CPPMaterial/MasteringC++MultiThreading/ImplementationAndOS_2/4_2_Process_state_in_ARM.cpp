/**
 * In ARM architectures, applications usually run in the unprivileged Exception Level 0 (EL0) level, which is 
 * comparable to ring 3 on x86 architectures, and the OS kernel in EL1. The ARMv7 (AArch32, 32-bit) architecture 
 * has the SP in the general purpose register 13. For ARMv8 (AArch64, 64-bit), a dedicated SP register is 
 * implemented for each exception level: SP_EL0, SP_EL1, and so on. 
 * 
 * For task state, the ARM architecture uses Program State Register (PSR) instances for the Current Program 
 * State Register (CPSR) or the Saved Program State Register (SPSR) program state's registers. The PSR is 
 * part of the Process State (PSTATE), which is an abstraction of the process state information. 
 * 
 * While the ARM architecture is significantly different from the x86 architecture, when using software-based 
 * task switching, the basic principle does not change: save the current task's SP, register state, and put 
 * the next task's detail in there instead before resuming processing.
 */