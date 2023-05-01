#ifndef LAB2SEM1__DOUBLE_H
#define LAB2SEM1__DOUBLE_H

typedef struct _double{
    double value;
}_double;

_double* InitDouble(int Value);
_double* InputDouble();
void PrintDouble(_double* Number);
int ComparisonDouble(const void* FirstNumber, const void* SecondNumber);
_double* SumDouble(_double* FirstNumber, _double* SecondNumber);
_double* SubtDouble(_double* FirstNumber, _double* SecondNumber);
void ClearDouble(_double *value);

#endif
