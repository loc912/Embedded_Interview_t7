#include <stdio.h>

// #define STM32 
#ifndef STM32 //bat dau 

int a = 10;

#endif 
#define Size 20
#if Size > 20 

int a = 30;

#elif Size ==20

int a = 20;

#else 

int a = 10;

#endif