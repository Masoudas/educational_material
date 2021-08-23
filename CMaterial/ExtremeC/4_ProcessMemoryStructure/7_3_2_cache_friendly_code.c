/**
 * When the CPU is executing an instruction, it has to fetch all required data first. The data is located in the 
 * main memory at a specific address that is determined by the instruction.
 * 
 * The data has to be transferred to the CPU registers before any computation. But the CPU usually brings more 
 * blocks than are expected to be fetched and puts them inside its cache. Next time, if a value is needed in the 
 * proximity of the previous address, it should exist in the cache, and the CPU can use the cache instead of the 
 * main memory, which is far faster than reading it from the main memory. As we explained in the previous section, 
 * this is a cache hit. If the address is not found in the CPU cache, it is a cache miss, and the CPU has to 
 * access the main memory to read the target address and bring required data which is quite slow. In general, 
 * higher hit rates result in faster executions.
 * 
 * But why does the CPU fetch the neighboring addresses (the proximity) around an address? It is because of the 
 * principle of locality. In computer systems, it is usually observed that the data located in the same 
 * neighborhood is more frequently accessed. So, the CPU behaves according to this principle and brings more data 
 * from a local reference. If an algorithm can exploit this behavior, it can be executed faster by the CPU. This 
 * is why we refer to such algorithm as a cache-friendly algorithm.
 * 
 * For example, below we implement the matrix in a row-major way. As such, it's conceivable that a row is dragged
 * from the memory all together. Therefore, performing operations on row elements directly will result in cache
 * misses.
 * 
 * We can in fact time the resulting code to compare notes:

time ./program friendly-sum 20000 20000
Friendly sum: 1585447424, 
real   0m5.192s		user   0m3.142s		sys    0m1.765s

time ./program not-friendly-sum 20000 20000
Not friendly sum: 1585447424
real   0m15.372s	user   0m14.031s	sys    0m0.791s

 * 
 */

#include <stdio.h>  // For printf function
#include <stdlib.h> // For heap memory functions
#include <string.h> // For strcmp function
void fill(int* matrix, int rows, int columns) {
    int counter = 1;
    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < columns; j++) {
      	*(matrix + i * columns + j) = counter;
    }
    counter++;
  }
}

void print_matrix(int* matrix, int rows, int columns) {
 	printf("Matrix:\n");
	for (int i = 0; i < rows; i++) {
  	  for (int j = 0; j < columns; j++) {
  	    printf("%d ", *(matrix + i * columns + j));
    }
    printf("\n");
  }
}

void print_flat(int* matrix, int rows, int columns) {
  printf("Flat matrix: ");
  for (int i = 0; i < (rows * columns); i++) {
    printf("%d ", *(matrix + i));
  }
  printf("\n");
}

int friendly_sum(int* matrix, int rows, int columns) {
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      sum += *(matrix + i * columns + j);
    }
  }
  return sum;
}

int not_friendly_sum(int* matrix, int rows, int columns) {
	int sum = 0;
	for (int j = 0; j < columns; j++) {
	    for (int i = 0; i < rows; i++) {
	    	sum += *(matrix + i * columns + j);
	    }
	}
	return sum;
}

int main(int argc, char** argv) {
	if (argc < 4) {
	  printf("Usage: [print|friendly-sum|not-friendly-sum] ");
	  printf("[number-of-rows] [number-of-columns]\n");
	  exit(1);
	} 

	char* operation = argv[1];
	int rows = atol(argv[2]);
	int columns = atol(argv[3]);
	int* matrix = (int*)malloc(rows * columns * sizeof(int));
	
	fill(matrix, rows, columns);
	if (strcmp(operation, "print") == 0) {
	  print_matrix(matrix, rows, columns);
	  print_flat(matrix, rows, columns);
	}
	else if (strcmp(operation, "friendly-sum") == 0) {
	  int sum = friendly_sum(matrix, rows, columns);
	  printf("Friendly sum: %d\n", sum);
	}
	else if (strcmp(operation, "not-friendly-sum") == 0) {
	  int sum = not_friendly_sum(matrix, rows, columns);
	  printf("Not friendly sum: %d\n", sum);
	}
	else {
	  printf("FATAL: Not supported operation!\n");
	  exit(1);
	}

	free(matrix);
	return 0;
}