#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"
#include "value.h"

// one-byte operation code
typedef enum {
    OP_RETURN,
} OpCode; 

typedef struct {
    int count; // num of bytes currently in chunk
    int capacity; // total number of bytes allocated for the chunk 
    uint8_t* code; // pointer to actual array of bytes 
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);
int addConstant(Chunk* chunk, Value value);

#endif