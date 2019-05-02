#include <iostream>
#include <string>

using namespace std;

class writeReg
{

  public:
    int *ALUControlM; /* ALUControl --> 1 = add, 2 = sub, 3 = mult, 4 = xor*/
    int *RegWriteM;
    int *MemWriteM;

    writeReg(int *ALUControlE, int *RegWriteE, int *MemWriteE, int *ALUResultE)
    {
        ALUControlM = ALUControlE;
        RegWriteM = RegWriteE;
        MemWriteM = MemWriteE;
    }
};