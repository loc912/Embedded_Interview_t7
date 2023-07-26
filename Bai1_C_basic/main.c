#include <stdio.h>
//#include <stdint.h>


// typedef
typedef int typeInt;
typedef unsigned char uint8_t;
typedef unsigned char uint16_t;
typedef unsigned char uint32_t;
typedef unsigned char uint64_t;

typedef short int8_t;
typedef short int16_t;
typedef short int32_t;
typedef short int64_t;
// Variable
uint8_t var;        
int8_t a;             
uint16_t var1;
int16_t b;
uint32_t var2;
int32_t c;
uint64_t var3;
int64_t d;

//Functon 
void tong(int a, int b){
  printf("tong %d va %d = %d\n", a, b, a+b);

}

//struct
struct toaDo{
  uint8_t x;
  uint8_t y;
}diemM;

typedef struct {
  uint8_t x;
  uint8_t y;
}toaDo;
// type enum 
typedef enum{
    thu2=2,
    thu3,
    thu4,
    thu5,
    thu6,
    thu7,
    CN
}Thu;

int main()
{
  //cau dieu kien
  /*for(uint8_t i=0; i < 10; i++){
    printf("i = %d\n",i);
  }

  int i=0;
  while(i<10){
    printf("i = %d\n",i);
    i++;
  }

  do
  {
    printf("i = %d\n",i);
  } while (i<10);
  
  int diem = 8;
  if(diem >= 7){
    printf("hoc sinh kha\n");
  }else if(diem >=8){
    printf("hoc sinh gioi\n");
  }else{
    printf("hoc sinh TB\n");
  }*/

  Thu thu=thu2;
  switch (thu)
  {
    case thu2:
        printf("thu 2\n");
        break;
    case thu3:
        printf("thu 3\n");
        break;
    case thu4:
        printf("thu 4\n");
        break;
    case thu5:
        printf("thu 5\n");
        break;
    case thu6:
        printf("thu 6\n");
        break;
    case thu7:
        printf("thu 7\n");
        break;
    case CN:
        printf("CN\n");
        break;
    default:
        printf("KO HOP LE\n"); 
        break;
  }
  
  return 0;
}