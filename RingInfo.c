#include "RingInfo.h"

RingInfo *CreateRing(void* (*input)(),
        void (*print)(void*),
        void* (*init)(void*),
        int (*comparison)(const void*, const void *),
        void* (*sum)(void*, void*),
        void* (*subt)(void*, void*),
        size_t size,
        void (*clear)(void *))
        {

    RingInfo* Ring = (RingInfo*) malloc(sizeof(RingInfo));
    Ring -> input = input;
    Ring -> print = print;
    Ring -> init = init;
    Ring -> comparison = comparison;
    Ring -> sum = sum;
    Ring -> subt = subt;
    Ring -> size = size;
    Ring -> clear = clear;
    return Ring;
}

void ClearRing(RingInfo *Ring){
    free(Ring);
}
