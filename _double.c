#include <stdlib.h>
#include <stdio.h>
#include "_double.h"

_double* InitDouble(int Value){
    _double* number = (_double*)malloc(sizeof(_double));
    number -> value = Value;
    return number;
}

_double* InputDouble(){
    printf(">>");
    double value;
    while (scanf("%lf", &value) != 1){
        scanf("%*[^\n]\n");
        printf("Not Correct");
    }
    _double* result = InitDouble(value);
    return result;
}

void PrintDouble(_double* Number){
    printf(">>> %lf\n",Number -> value);
}

int ComparisonDouble(const void* FirstNumber, const void* SecondNumber){
    _double *first = *(_double**)FirstNumber;
    _double *second = *(_double**)SecondNumber;
    return (first->value > second->value) - (first->value < second->value);
}

_double* SumDouble(_double* FirstNumber, _double* SecondNumber){
    _double* result = InitDouble(FirstNumber->value + SecondNumber->value);
    return result;
}

_double* SubtDouble(_double* FirstNumber, _double* SecondNumber){
    _double* result = InitDouble(FirstNumber->value - SecondNumber->value);
    return result;
}

void ClearDouble(_double *value){
    free(value);
}