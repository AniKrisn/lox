#include "common.h"
#include "memory.h"
#include "chunk.c"

int main(int argc, const char* argv) {
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    freeChunk(&chunk);

    disassembleChunk(&chunk, "test chunk");

    return 0;
}