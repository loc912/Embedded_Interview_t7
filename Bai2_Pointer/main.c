#include <stdio.h>

void tong(int a, int b){
    printf("Tong cua %d + %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu cua %d - %d = %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("Tich cua %d * %d = %d\n", a, b, a*b);
}
void tinhtoan(void(*func)(int,int),int a, int b){
    printf("tinh toan\n");
    func(a,b);
}
void main(){   

    // con tro ham
    tinhtoan(&tong,4,9);
    tinhtoan(&hieu,9,4);
    tinhtoan(&tich,5,2);
    //ep kieu con tro void
    void *ptr[] = {tong, hieu, tich};
    ((void (*)(int, int))ptr[2])(7,5);
    // con tro NULL  
    int *ptr1 = NULL;
    printf("test con tro Null : %p\n",ptr);

}