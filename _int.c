#include <stdlib.h>
#include <stdio.h>
#include "_int.h"

_int* InitInt(int Value){
    _int* number = (_int*)malloc(sizeof(_int));
    number -> value = Value;
    return number;
}

_int* InputInt(){
    printf(">>");
    int value = -1;
    while (scanf("%d", &value) != 1 || value % 1 != 0){
        scanf("%*[^\n]\n");
        printf("Not Correct");
    }
    _int* result = InitInt(value);
    return result;
}

void PrintInt(_int* Number){
    printf(">>> %d\n",Number -> value);
}

int ComparisonInt(const void* FirstNumber, const void* SecondNumber){
    _int *firstNumber = *(_int**)FirstNumber;
    _int *secondNumber = *(_int**)SecondNumber;
    return (firstNumber->value > secondNumber->value) - (firstNumber->value < secondNumber->value);
}

//int ComparisonInt(_int* FirstNumber, _int* SecondNumber){
//
//    int result = -1;
//    if (FirstNumber->value > SecondNumber->value){result = 1;}
//    if(result == -1){result = (FirstNumber->value == SecondNumber->value) ? 0 : -1;}
//    return result;
//}

_int* SumInt(_int* FirstNumber, _int* SecondNumber){
    _int* result = InitInt(FirstNumber->value + SecondNumber->value);
    return result;
}

_int* SubtInt(_int* FirstNumber, _int* SecondNumber){
    _int* result = InitInt(FirstNumber->value - SecondNumber->value);
    return result;
}

void ClearInt(_int* value){
    free(value);
}