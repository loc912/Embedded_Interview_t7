#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 

    // TEXt //biến const sẽ được lưu trong vùng nhớ Text
const int i=10;

    // DATA //giá trị biến khởi tạo khác 0 thì được lưu trong vùng nhớ Data
int a = 10;              //biến toàn cục
static int b = 20;       //biến static toàn cục
void test(){
    static int c = 30;   //biến static cục bộ
}

    // BSS //giá trị khởi tạo bằng 0 hoặc không có giá trị thì được lưu trong vùng nhớ Bss
int a1=0;        //khởi tạo bằng 0
static int b1;   //không khởi tạo giá trị

    // STACK // Sẽ được giải phóng khi ra khỏi block code/hàm
void test1(){
    uint8_t array[5];
    printf("Dia chi: %p\n",array);
}

    // HEAP // Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc
void test2(){
    uint8_t *array = (uint8_t*)malloc(sizeof(uint8_t)*5);
    printf("Dia chi: %p\n",array);
    //free(array); //thu hồi bộ nhớ 
}


int main(int argc, char const *argv[])
{
    test1();
    test1();
    
    test2();
    test2();

    return 0;
}
