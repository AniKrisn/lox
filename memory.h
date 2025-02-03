#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"
#include <stdlib.h>

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    // when oldSize != 0 && newSize == 0: simply deallocate (by freeing pointer)
    // if that block is used in future we overwrite with init 
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    // other three cases, realloc handles:
    void* result = realloc(pointer, newSize); // realloc method resizes prev allocated mem block without losing its contents
    if (result == NULL) exit(1); // if run out of memory
    return result;
}

#endif