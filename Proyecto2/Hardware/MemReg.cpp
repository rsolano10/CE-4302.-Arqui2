#include <iostream>
#include <string>

using namespace std;

class memReg
{

  public:
    int *RegWriteM;
    int *MemWriteM;
    string *ALUResultM;    
    int *memToRegM;
    int *RdM;

    memReg(int *RegWriteE, int *MemWriteE, string *ALUResultE, int *memtToRegE, int *RdE)
    {
        RegWriteM = RegWriteE;
        MemWriteM = MemWriteE;
        ALUResultM = ALUResultE;
        memToRegM = memtToRegE;
        RdM = RdE;
    }
};