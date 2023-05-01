#include "FunctionArray.h"
#include <stdio.h>
#include <string.h>

DynamicArray *CreateArray(RingInfo *Ring){
    int len = -1;
    printf("Please, Input length of array\n>");
    while (scanf("%d", &len) != 1 || len % 1 != 0 || len <= 0){
        scanf("%*[^\n]\n");
    }
    DynamicArray* Array = (DynamicArray*) malloc(sizeof(DynamicArray));
    Array -> size = len;
    Array -> array = (void**)malloc(Array -> size * Ring->size);
    return Array;
}

DynamicArray *InputArray(RingInfo *Ring){
    DynamicArray* Array = CreateArray(Ring);
    for (int i = 0; i < Array-> size; ++i) {
        Array ->array[i] = Ring->input();
    }
    printf("\n");
    return Array;
}



void PrintArray(DynamicArray *Array, RingInfo *Ring){
    for (int i = 0; i < Array->size; ++i) {
        printf("Index %d ",i);
        (Ring->print(Array->array[i]));
    }
}

DynamicArray *ArrayCat(DynamicArray *FirstArray,DynamicArray *SecondArray,RingInfo *Ring){
    DynamicArray* AnsArray = (DynamicArray*)malloc(sizeof (DynamicArray));
    AnsArray->size = (FirstArray->size) + (SecondArray->size);
    AnsArray->array = (void**)malloc(AnsArray->size * Ring->size);
    memcpy(AnsArray->array,FirstArray->array,FirstArray-> size* Ring->size);
    memcpy(AnsArray->array + FirstArray-> size ,SecondArray->array,SecondArray-> size* Ring->size);
    return AnsArray;
}

DynamicArray* SortArray(RingInfo *RingFunction, DynamicArray *Array){
    qsort(Array->array,
          Array->size,
          RingFunction -> size,
           RingFunction->comparison);
    return Array;
}

DynamicArray* Add(RingInfo *Ring, DynamicArray *Array){
    printf("Input elements\n");
    void *key = Ring->input();
    Array -> size +=1;
    Array ->array = (void **)realloc(Array->array, Array->size * Ring->size);
    Array->array[Array->size - 1] = key;
    return Array;
}

DynamicArray* Remove(RingInfo *Ring, DynamicArray *Array){
    if (Array->array == NULL){return NULL;}
    int key = -1;
    printf("input delete key\n");
    while (scanf("%d", &key) != 1 || key % 1 != 0 || key < 0 || key > Array->size-1){
        scanf("%*[^\n]\n");
        printf("Incorrect\n");
    }
    for (int i = 0; i < Array->size-1; ++i) {
        Array->array[key+i]= Array->array[key+i+1];
    }
    Array -> size -=1;
    Array ->array = (void **)realloc(Array->array, Array->size * Ring->size);
    return Array;
}

DynamicArray* MapArray(DynamicArray *Array, void* (*Function)(void*)){
    for (int i = 0; i < Array->size; ++i) {
        Function(Array->array[i]);
    }
    return Array;
}

int IndexOf(DynamicArray *Array, RingInfo *Ring){
    printf("Input key\n");
    void *key = Ring->input();
        for (int i = 0; i < Array-> size; i++) {
            if (Ring -> comparison(&(Array->array[i]), &key)==0) {
                return i;
            }
        }
        return -1;
}

void clear(DynamicArray *Array, RingInfo *Ring){
    for (int i = 0; i < Array->size; ++i) {
        Ring->clear(Array->array[i]);
    }
}


