#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"

// one-byte operation code
typedef enum {
    OP_RETURN,
} OpCode; 

typedef struct {
    int count; // num of bytes currently in chunk
    int capacity; // total number of bytes allocated for the chunk 
    uint8_t* code; // pointer to actual array of bytes 
} Chunk;

void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL; // don't point to non-valid memory
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk); // zero out fields, leaving chunk in a well-defined empty state
}

// write a byte into the chunk, grow chunk capacity if required
void writeChunk(Chunk* chunk, uint8_t byte) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}


#endif