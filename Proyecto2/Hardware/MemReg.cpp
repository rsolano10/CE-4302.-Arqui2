#include <iostream>
#include <string>

using namespace std;

class memReg
{

  public:
    int *ALUControlM; /* ALUControl --> 1 = add, 2 = sub, 3 = mult, 4 = xor*/
    int *RegWriteM;
    int *MemWriteM;
    int *ALUResultM;    

    memReg(int *ALUControlE, int *RegWriteE, int *MemWriteE, int *ALUResultE)
    {
        ALUControlM = ALUControlE;
        RegWriteM = RegWriteE;
        MemWriteM = MemWriteE;
        ALUResultM = ALUResultE;
    }
};