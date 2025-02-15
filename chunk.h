#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"
#include "value.h"

// one-byte operation code
typedef enum {
    OP_CONSTANT, // to load + execute constants
    OP_ADD, 
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE, 
    OP_RETURN, // to return
} OpCode; 

typedef struct {
    int count; // num of bytes currently in chunk
    int capacity; // total number of bytes allocated for the chunk 
    uint8_t* code; // pointer to actual array of bytes 
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif