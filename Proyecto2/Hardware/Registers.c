#include <stdio.h>
#define REGSIZE 32

// General porpouse registers
int* R1;
int* R2;
int* R3;
int* R4;
int* R5;
int* R6;
int* R7;
int* R8;
int* R9;
int* R10;

void initRegisters(){
    R1 = calloc(REGSIZE,sizeof(int));
    R2 = calloc(REGSIZE,sizeof(int));
    R3 = calloc(REGSIZE,sizeof(int));
    R4 = calloc(REGSIZE,sizeof(int));
    R5 = calloc(REGSIZE,sizeof(int));
    R6 = calloc(REGSIZE,sizeof(int));
    R7 = calloc(REGSIZE,sizeof(int));
    R8 = calloc(REGSIZE,sizeof(int));
    R9 = calloc(REGSIZE,sizeof(int));
    R10 = calloc(REGSIZE,sizeof(int));
}