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
  string *ImmE;
  string *isImmE;

  execReg(int *ALUControlD, int *RegWriteD, int *MemWriteD, string *Rd1, string *Rd2, int *memtoReg, int *RdD, string *Imm, string *isImmOp)
  {
    ALUControlE = ALUControlD;
    RegWriteE = RegWriteD;
    MemWriteE = MemWriteD;
    Rd1E = Rd1;
    Rd2E = Rd2;
    memtoRegE = memtoReg;
    RdE = RdD;
    ImmE = Imm;
    isImmE = isImmOp;
  }
};