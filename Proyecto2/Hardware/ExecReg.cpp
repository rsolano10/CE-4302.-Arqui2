#include <iostream>
#include <string>

using namespace std;

class execReg
{

public:
  int *ALUControlE; /* ALUControl --> 1 = add, 2 = sub, 3 = mult, 4 = xor*/
  int *RegWriteE;
  int *MemWriteE;
  string *Rd1E;
  string *Rd2E;
  int *memtoRegE;
  int *RdE;

  execReg(int *ALUControlD, int *RegWriteD, int *MemWriteD, string *Rd1, string *Rd2, int *memtoReg, int *RdD)
  {
    ALUControlE = ALUControlD;
    RegWriteE = RegWriteD;
    MemWriteE = MemWriteD;
    Rd1E = Rd1;
    Rd2E = Rd2;
    memtoRegE = memtoReg;
    RdE = RdD;
  }
};