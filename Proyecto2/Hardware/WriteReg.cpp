#include <iostream>
#include <string>

using namespace std;

class writeReg
{
  private:
    int *memtoRegW;
    
  public:
    int *RegWriteW;
    int *MemWriteW;
    string *dataout;
    string *ALUdata;
    int *regWrite2;
    string writedata;
    int *RdW;

    writeReg(int *RegWriteE, int *MemWriteE, string *ALUResultE,string *memout, int *regWriteFlag, int *memtoRegM, int *RdM)
    {
        RegWriteW = RegWriteE;
        MemWriteW = MemWriteE;
        ALUdata = ALUResultE;
        dataout = memout;
        regWrite2 = regWriteFlag;
        memtoRegW = memtoRegM;
        RdW = RdM;
    }

    void updateFlags(){
      regWrite2 = RegWriteW;
      if(*memtoRegW == 1){
        writedata = *dataout;
      }
      else{
        writedata = *ALUdata;
      }
    }

};