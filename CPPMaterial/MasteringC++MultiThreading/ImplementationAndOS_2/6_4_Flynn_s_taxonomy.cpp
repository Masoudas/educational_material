/**
 * Different types of computer architecture are classified using a system which was first proposed by Michael 
 * J. Flynn, back in 1966. This classification system knows four categories, defining the capabilities of the 
 * processing hardware in terms of the number of input and output streams:
 * 
 *      -   Single Instruction, Single Data (SISD): A single instruction is fetched to operate on a single 
 *          data stream. This is the traditional model for CPUs. (A moden PC CPU)
 *      -   Single Instruction, Multiple Data (SIMD): With this model, a single instruction operates on 
 *          multiple data streams in parallel. This is what vector processors such as graphics processing 
 *          units (GPUs) use.
 *      -   Multiple Instruction, Single Data (MISD): This model is most commonly used for redundant systems, 
 *          whereby the same operation is performed on the same data by different processing units, validating 
 *          the results at the end to detect hardware failure. This is commonly used by avionics systems and 
 *          similar.
 *      -   Multiple Instruction, Multiple Data (MIMD): For this model, a multiprocessing system lends itself 
 *          very well. Multiple threads across multiple processors process multiple streams of data. These 
 *          threads are not identical, as is the case with SIMD.
 * 
 * Me: If I may recall, with GPU processing with nvidia, this was exactly what we do. We write a function,
 * that contains one instruction set (like addition) then we pass to it a pointer to all our data.
 * 
 * Me: Should I assume that modern CPUs are MIMD? Nope. This is a highly sophisticated model. In fact, most
 * CPUs on modern computers are SISD. This is because as we may recall earlier, the CPU of intel for example
 * able to receive one TTS with stack and execute it.
 * 
 * An important thing to note with these categories is that they are all defined in terms of multiprocessing, 
 * meaning that they refer to the intrinsic capabilities of the hardware. Using software techniques, virtually 
 * any method can be approximated on even a regular SISD-style architecture. This is, however, part of 
 * multithreading.
 */