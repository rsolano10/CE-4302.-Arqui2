#include <iostream>
#include <string>

using namespace std;

class execReg
{

public:
  int *ALUControlE; /* ALUControl --> 1 = add, 2 = sub, 3 = mult, 4 = xor*/
  int *RegWriteE;
  int *MemWriteE;
  int *Rd1E;
  int *Rd2E;

  execReg(int *ALUControlD, int *RegWriteD, int *MemWriteD, int *Rd1, int *Rd2)
  {
    ALUControlE = ALUControlD;
    RegWriteE = RegWriteD;
    MemWriteE = MemWriteD;
    Rd1E = Rd1;
    Rd2E = Rd2;
  }
};