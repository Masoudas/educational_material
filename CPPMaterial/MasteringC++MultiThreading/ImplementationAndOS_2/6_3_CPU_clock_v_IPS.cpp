/**
 * Instructions Per Second (IPC), instead of the GHz rating of a CPU, is generally far more significant for 
 * determining the sheer performance of a CPU.
 * 
 * 
 * ME: If I run:
 * $ lshw -class cpu
 * 
 * I get the following:
 
 product: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz
       vendor: Intel Corp.
       physical id: 1
       bus info: cpu@0
       size: 2445MHz
       capacity: 5GHz
       width: 64 bits

 * So my current CPU has a maximum 5GHz clock. Apparently we can get the number of instructions run per
 * program with the following command:
 * 
 * $ perf stat --all-user ./my_program
 
 2,42 msec task-clock                #    1,006 CPUs utilized          
                 0      context-switches          #    0,000 K/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
               146      page-faults               #    0,060 M/sec                  
         1 948 630      cycles                    #    0,805 GHz                    
         2 664 609      instructions              #    1,37  insn per cycle         
           423 780      branches                  #  175,103 M/sec                  
            14 833      branch-misses             #    3,50% of all branches  

 * This is the result for the program in chapter one. Note that it does not give IPS, but we can calculate
 * it for this sample program using n-instructions and of course cpu cycle. But this is a bit more elaborate
 * and I should search "calculate IPS with perf stat"
 */