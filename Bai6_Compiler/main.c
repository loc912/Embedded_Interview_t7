#include<stdio.h>
#include "test.c" 

#define SIZE 20
#define sum(a,b) a+b

int var = 10;

int main(int argc, char const *argv[])
{\
    test();
    //array
    int array[SIZE];

    printf("tong a va b = %d\n",sum(5,6));
    return 0;
}
