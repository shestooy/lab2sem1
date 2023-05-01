
#ifndef LAB2SEM1__INT_H
#define LAB2SEM1__INT_H

typedef struct _int{
    int value;
}_int;

_int* InitInt(int Value);
_int* InputInt();
void PrintInt(_int* Number);
int ComparisonInt(const void* FirstNumber, const void* SecondNumber);
//int ComparisonInt(_int* FirstNumber, _int* SecondNumber);
_int* SumInt(_int* FirstNumber, _int* SecondNumber);
_int* SubtInt(_int* FirstNumber, _int* SecondNumber);
void ClearInt(_int* value);

#endif
