#include<stdio.h> 


int count = 10;

static int temp =10; // chỉ được sử dụng trong file này ko thể extern và ko có cách nào lấy được. 

void test(){
    //static int a = 10; //0xc1
    printf("Count = %d\n",count);
    count++;
}

int *ptr(){
    static int a = 10;
    return &a;
}
