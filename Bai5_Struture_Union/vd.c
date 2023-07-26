#include <stdio.h> 
#include <stdint.h>

typedef union{
    struct 
    {
        uint8_t id[2];
        uint8_t data[3];
        uint8_t checkSum[1];
    }object;
    uint8_t array[6]; 
}dataFame;

int main(int argc, char const *argv[])
{
    // Goi data can phai truyen : 2byte ID
    //                            3byte Data
    //                            1byte CS

    dataFame test;

    test.object.id[0]= 0x01;
    test.object.id[0]= 0x02;

    test.object.data[0]= 0xC2;
    test.object.data[1]= 0xC3;
    test.object.data[2]= 0xC4;

    test.object.checkSum[0]= 0xA1;



    return 0;
}

