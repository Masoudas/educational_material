/**
 * Over the past decades, many systems were created which contained multiple processing units. These can be 
 * broadly divided into Symmetric Multiprocessing (SMP) and Asymmetric Multiprocessing (AMP) systems.
 * 
 * AMP's main defining feature is that a second processor is attached as a peripheral to the primary CPU. 
 * This means that it cannot run control software, but only user applications. This approach has also been 
 * used to connect CPUs using a different architecture to allow one to, for example, run x86 applications 
 * on an Amiga, 68k-based system. (Me: apparently, the control software here implies the OS. Hence, one core
 * is dedicated to OS, and others to user programs. Also No Communication between Processors as they are 
 * controlled by the master processor. Hence, are cheaper and easier to design. I think possibly slower.)
 * 
 * With an SMP system, each of the CPUs are peers having access to the same hardware resources, and set up 
 * in a cooperative fashion. Initially, SMP systems involved multiple physical CPUs, but later, multiple 
 * processor cores got integrated on a single CPU die (Fig6. Why only one CPU has access RAM? Perhaps because
 * only the master CPU is allowed to manage HW, as it's the OS core.)
 * 
 * With the proliferation of multi-core CPUs, SMP is the most common type of processing outside of embedded 
 * development, where uniprocessing (single core, single processor) is still very common. 
 * 
 * Technically, the sound, network, and graphic processors in a system can be considered to be asymmetric 
 * processors related to the CPU. With an increase in General Purpose GPU (GPGPU) processing, AMP is 
 * becoming more relevant.
 */