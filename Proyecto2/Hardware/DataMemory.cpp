#include <iostream>
#define DATAMEMSIZE 5000000

using namespace std;

class dataMemory
{
  private:
    int dataMem[DATAMEMSIZE];
    int headDataMem;
    int *ALUinput;
    int *dirInput;
  
  public:
    int memResult;
    dataMemory(int *ALUResult, int *DataPath){
      headDataMem = 0;
      ALUinput = ALUResult;
      dirInput = DataPath;
    }

    void writeDataMem(int data)
    {
        dataMem[*dirInput] = (int) data;
    }

    int readDataMem()
    {
        return *(dataMem + *dirInput);
    }

    void uploadImage(int data){
      dataMem[headDataMem] = (int) data;
      headDataMem++;
    }
};