#include "GUI.h"
#include <stdio.h>
#include <stdlib.h>


RingInfo *FirstMenu(){
    int key = 0;
    printf("Please, input value in rage:\n 1-Int Array\n 2-Double Array\n 3-Exit\n>");

    while(scanf("%d", &key) != 1 || key % 1 != 0 || (key != 1 && key != 2 && key != 3)){
        scanf("%*[^\n]\n");
        printf("Incorrect value\n");

    }

    switch (key){
        case 1:
        {
           return CreateRing((void *(*)(void *)) InputInt,
                       (void (*)(void *)) PrintInt,
                       (void *(*)(void *)) InitInt,
                       ComparisonInt,
                       (void *(*)(void *, void *)) SumInt,
                       (void *(*)(void *, void *)) SubtInt,
                       sizeof(void *),
                       (void (*)(void *)) ClearInt);
        };
        case 2:
        {
            return CreateRing((void *(*)(void *)) InputDouble,
                       (void (*)(void *)) PrintDouble,
                       (void *(*)(void *)) InitDouble,
                       ComparisonDouble,
                       (void *(*)(void *, void *)) SumDouble,
                       (void *(*)(void *, void *)) SubtDouble,
                       sizeof(void *),
                       (void (*)(void *)) ClearDouble);
        };
        case 3:{
            exit(0);
        }
    }
    return NULL;
}

void PrintMainMenu(){
    printf("\n\n-----------------------------\n");
    printf("1-Create New Array\n");
    printf("2-Create New Ring\n");
    printf("3-Add element\n");
    printf("4-Remove element\n");
    printf("5-Concat Array(Need 1 more input Array)\n");
    printf("6-Sort Array\n");
    printf("7-Map\n");
    printf("8-IndexOf\n");
    printf("9-Exit\n");
    printf("-----------------------------\n");

}
void MainMenu(){
    RingInfo *Ring = FirstMenu();
    DynamicArray *Array = InputArray(Ring);
    system("cls");
    int key;

    do {
        PrintArray(Array, Ring);
        PrintMainMenu();
        while(scanf("%d", &key) != 1){
            scanf("%*[^\n]\n");
            printf("Incorrect value\n");
        }
        printf("\n");
        switch (key) {
            case 1: {
                clear(Array, Ring);
                Array = InputArray(Ring);
                system("cls");
                break;
            };
            case 2:{
                clear(Array,Ring);
                ClearRing(Ring);
                Ring = FirstMenu();
                Array = InputArray(Ring);
                system("cls");
                break;
            }
            case 3:{
                Add(Ring,Array);
                system("cls");
                break;
            }
            case 4:{
                Remove(Ring,Array);
                system("cls");
                break;
            }
            case 5: {
                printf("Input Second Array\n");
                DynamicArray *SecondArray = InputArray(Ring);
                Array = ArrayCat(Array, SecondArray, Ring);
                system("cls");
                free(SecondArray);
                break;
            };
            case 6:
            {
                Array = SortArray(Ring,Array);
                system("cls");
                break;
            };
            case 7:
            {
                break;
            };
            case 8:{
                system("cls");
                PrintArray(Array,Ring);
                printf("Index: %d\n",IndexOf(Array,Ring));
                break;
            };
            case 9:{
                clear(Array,Ring);
                ClearRing(Ring);
                break;
            }

            default: {
                key = 0;
                system("cls");
                break;
            }
        }
    } while (key != 9);
}