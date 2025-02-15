#include <stdio.h>
#include <time.h>

#include "common.h"
#include "memory.h"
#include "chunk.h"
#include "debug.h"
#include "value.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    clock_t start = clock();

    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123); 

    
    writeChunk(&chunk, OP_NEGATE, 123);
    writeChunk(&chunk, OP_RETURN, 123);
    

    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();

    freeChunk(&chunk);

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Interpreter execution took %f seconds\n", cpu_time_used);

    return 0;
}