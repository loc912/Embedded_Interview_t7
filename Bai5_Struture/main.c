#include <stdio.h> 
#include <stdint.h>

typedef union {
    uint8_t var1;
    uint16_t var2[10];
    uint64_t var3[2];
}typeUnion;

int main(void){
    typeUnion var;

    printf("Dia chi Var: %p\n", &var);

    printf("Dia chi Var1: %p\n", &var.var1);

    printf("Dia chi Var2: %p\n", &var.var2);

    printf("Dia chi Var3: %p\n", &var.var3);

    printf("size : %lu\n", sizeof(typeUnion));

    return 0;
}