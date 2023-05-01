#ifndef LAB2SEM1_RINGINFO_H
#define LAB2SEM1_RINGINFO_H
#include <stdlib.h>


typedef struct RingInfo{
    void* (*input)();
    void (*print)(void*);
    void (*clear)(void *);

    void* (*init)(void*);
    int (*comparison)(const void*,const void *);

    void* (*sum)(void*, void*);
    void* (*subt)(void*, void*);// вычитание "-"
    size_t size;

}RingInfo;


RingInfo *CreateRing(void* (*input)(),
                    void (*print)(void*),
                    void* (*init)(void*),
                    int (*comparison)(const void*,const void *),
                    void* (*sum)(void*, void*),
                    void* (*subt)(void*, void*),
                    size_t size,
                    void (*clear)(void *));


void ClearRing(RingInfo *Ring);


#endif
