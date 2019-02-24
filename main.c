// Kayla Ritchie -- Programming Assignment 1

#include <stdio.h>
#include <stdlib.h>

// #1 Global var
int q = 15;

// #1 Methods
void noChange(int x){
    x =1;
}

void change(int *t) {
    *t = 7;

}

int anotherChange(int z) {
    return z + 2;

}

// #2 Methods
void swap_ends(char iarr[], int size) {
    int tmp = iarr[0];
    iarr[0] = iarr[size - 1];
    iarr[size - 1] = tmp;
}

// Section Methods
void pointerPractice() {
    printf("#1 Pointer practice:\n");
    int *p;
    printf("q = %d\n", q);
    p = &q;
    printf("q = %d\n", q);
    *p = 10;
    printf("q Original = %d\n", q);
    noChange(q);
    printf("q no change = %d\n", q);
    change(p);
    printf("q change = %d\n", q);
    q = anotherChange(q);
    printf("q changed again = %d\n\n", q);
};

void pointerArrayPractice() {
    printf("#2 Pointer-Array practice:\n");
    int zArray[3];
    int j = 6;
    for (int i = 0; i < 3; i++) {
        zArray[i] = j;
        j = j + 3;

    }
    float xArray[] = {15.0, 92.8, 8.0, 4.5};
    char sArray[] = "supercalifragilisticexpialidocious";
    int zSize = sizeof(zArray)/sizeof(zArray[0]);
    int xSize = sizeof(xArray)/sizeof(xArray[0]);
    int sSize = sizeof(sArray)/sizeof(sArray[0]);
    printf("Number of elements of zArray is %d\n", zSize);
    printf("Number of elements of xArray is %d\n", xSize);
    printf("Number of elements of sArray is %d\n", sSize);
    printf("zArray[2]: %d\n", zArray[2]);
    int *jarr = zArray;
    jarr[2] = jarr[2] + 1;
    zSize = sizeof(zArray)/sizeof(zArray[0]);
    printf("Number of elements of zArray is %d\n", zSize);
    printf("zArray[2]: %d\n\n", zArray[2]);
}

void arraysInFuctions() {
    char test[] = { "nights"};
    printf("#3 Working with Arrays in Functions practice: \n");
    printf("Before swap Start: %c; End: %c\n", test[0], test[5]);
    swap_ends(test, 6);
    printf("After swap Start: %c; End: %c\n\n", test[0], test[5]);
}

void structures() {
    struct pet_inventory {
        char type[10];
        float price;
        int numPets;
        int paws;
    };

    struct myInfo {
        char firstName[10];
        char lastName[10];
        int age;
        int classes;
    };
    printf("#4 Structure practice: \n");
    struct pet_inventory fluffy = { "cat", 850.25, 37, 4 };
    struct myInfo kayla = {"Kayla", "Ritchie", 27, 5};
    printf("Fluffy is a %s that costs %f dollars. We have %d of them. They have %d paws.\n", fluffy.type,
           fluffy.price,
           fluffy.numPets,
           fluffy.paws);
    struct myInfo* myPointer = &kayla;

    printf("%s %s is %d years old and is currently taking %d classes.\n\n", myPointer->firstName,
           myPointer->lastName,
           myPointer->age,
           myPointer->classes);
}

void stackAllocation() {
    printf("#6 Stack Allocation practice:\n");
    int *array_size = (int *) malloc(sizeof(int));
    int size = 8;
    if (array_size == NULL) {
        printf("ERROR: Memory allocation failed!\n");
    } else {
        *array_size = 10;
    }
    int *int_array = (int *) malloc(*array_size * sizeof(int));

    if (int_array == NULL) {
        printf("ERROR: Memory allocation failed!\n");
    } else {
        for (int i = 0; i < *array_size; i++) {
            int_array[i] = i * *array_size;
            printf("Array element %d holds %d\n", i, int_array[i]);
        }
    }
    free(array_size);
    array_size = NULL;
    free(int_array);
    int_array == NULL;

    double ***data_cube;
    data_cube = (double ***) malloc(sizeof(double **) * 1000);
    for (int i=0; i<1000; i++)
        data_cube[i] = (double **) malloc(sizeof(double *) * 1000);
    for (int i=0; i<1000; i++)
        for (int j=0; j<1000; j++)
            data_cube[i][j] = (double *) malloc(sizeof(double) * 1000);
    for (int i=0; i<1000; i++)
        for (int j=0; j<1000; j++)
            free(data_cube[i][j]);
    for (int i=0; i<1000; i++)
        free(data_cube[i]);
    free(data_cube);

}

int main() {
    // #1 Pointers
    pointerPractice();
    // #2 Pointer-array duality
    pointerArrayPractice();
    // #3 Working with Arrays in Functions
    arraysInFuctions();
    // #4 Structures
    structures();
    // #6 Stack Allocation
    stackAllocation();

    return 0;
}
