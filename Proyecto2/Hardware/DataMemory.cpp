#include <iostream>
#include <string>
#define DATAMEMSIZE 5000000

using namespace std;

class dataMemory
{
  private:
    string dataMem[DATAMEMSIZE];
    int headDataMem;
    string *ALUinput;
    int dirInput;
    int *flag;
  
  public:
    string memResult;
    dataMemory(string *ALUResult, int *memWriteM){
      headDataMem = 0;
      ALUinput = ALUResult;
      dirInput = 0;
      flag = memWriteM;
    }

    void writeDataMem(string data)
    {
        dataMem[dirInput] = (string) data;
    }

    string readDataMem()
    {
        return *(dataMem + dirInput);
    }

    void uploadImage(int data){
      dataMem[headDataMem] = (int) data;
      headDataMem++;
    }

    void operate(){
      if(*flag == 1){
        memResult = *ALUinput;
        writeDataMem(*ALUinput);
      }
      else{
        memResult = readDataMem();
      }
    }
};