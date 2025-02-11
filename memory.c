#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    // when oldSize != 0 && newSize == 0: simply deallocate (by freeing pointer)
    // if that block is used in future we overwrite with init 
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    // other three cases, realloc handles:
    void* result = realloc(pointer, newSize); // realloc method resizes prev allocated mem block without losing its contents
    if (result == NULL) exit(1); // if memory allocation fails (e.g if run out of memory)
    return result;
}