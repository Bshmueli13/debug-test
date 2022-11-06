#include <stdio.h> 
#include <stdlib.h> 
#pragma warning(disable:4996) //ADD #pragma warning(disable:4996)


int main()

{
    int x, y;
    int nums[6];
    int* arrPtr;

    x = 2;
    y = 5;  //added values to x and y 

    // Section A - Print the variables 

    puts("***** Section A *****");

    printf(" Base = %d\n", x);

    printf(" Height = %d\n", y);

    //print the resolte of x*y
    printf(" Area = %d\n", x * y);

    // Section B - Print the static array "nums". 
    puts("***** Section B *****");

    int i = 0;

    while (i < 6) {
        //ENTER TO nums in place I 
        //in double of 3
        nums[i] = i * 3;

        printf("  nums[%d] = %d\n", i, nums[i]);

        //Advance i by 1 in every itteration
        i++;
    }
    // Section C - Print allocated array. 

    puts("***** Section C *****");
    arrPtr = malloc(sizeof(int) * 6); //changed from 10 to 6 in size of

    int* arrPtrAssist = arrPtr; //added assisting arr

    for (i = 0; i < 6; i++)
    {
        //mult the arr in incraments of 5
        *arrPtrAssist = i * 5;

        //move the pointer if not the last run
        if (i != 5)
        {
            arrPtrAssist++;

        }

        // printf("  array[%d] = %d\n", i, arrPtr[i]);
    }

    if (arrPtr)
    {
        for (i = 0; i < 6; i++) {

            printf("  array[%d] = %d\n", i, arrPtr[i]);
        }
    }

    else {

        printf("Error Allocating Memory!\n");
        exit(1);
    }
    return 0;
}