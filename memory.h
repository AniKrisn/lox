#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    // when oldSize != 0 && newSize == 0: 
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    // other three cases, realloc handles:
    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1); // if run out of memory
    return result;
}

#endif