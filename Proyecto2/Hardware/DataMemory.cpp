#include <iostream>
#define DATAMEMSIZE 5000000

using namespace std;

class dataMemory
{
  private:
    int dataMem[DATAMEMSIZE];
    int headDataMem;
  
  public:
    
    dataMemory(){
        headDataMem = 0;
    }

    void writeDataMem(int data)
    {
        dataMem[headDataMem] = (int)data;
        headDataMem++;
    }

    int readDataMem(int pos)
    {
        return *(dataMem + pos);
    }
};