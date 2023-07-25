#include<stdio.h>
#include<time.h>

extern void test();

int main(void){

    clock_t start, end;

    double test;
    
    register int i ;
    start = clock();
    for ( i = 0; i < 0xffffff; i++);
    end = clock();
    test = (double)(end-start)/CLOCKS_PER_SEC;
    
    printf("time: %f\n",test);

    return 0;
}