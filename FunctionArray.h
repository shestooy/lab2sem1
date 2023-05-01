#ifndef LAB2SEM1_FUNCTIONARRAY_H
#define LAB2SEM1_FUNCTIONARRAY_H
#include <stdlib.h>
#include "RingInfo.h"

typedef struct DynamicArray{
    void* *array;
    size_t size;
}DynamicArray;

DynamicArray *CreateArray(RingInfo *Ring);
DynamicArray *InputArray(RingInfo *Ring);
void PrintArray(DynamicArray *Array, RingInfo *Ring);
DynamicArray *ArrayCat(DynamicArray *FirstArray,DynamicArray *SecondArray,RingInfo *Ring);
DynamicArray* SortArray(RingInfo *RingFunction, DynamicArray *Array);
DynamicArray* MapArray(DynamicArray *Array, void* (*Function)(void*));
DynamicArray* Add(RingInfo *Ring, DynamicArray *Array);
DynamicArray* Remove(RingInfo *Ring, DynamicArray *Array);
int IndexOf(DynamicArray *Array, RingInfo *Ring);
void clear(DynamicArray *Array, RingInfo *Ring);
#endif
