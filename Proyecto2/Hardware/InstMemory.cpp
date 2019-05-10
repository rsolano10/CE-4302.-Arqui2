#include <iostream>
#include <string>
#define INSTMEMSIZE 350000

using namespace std;
class instMemory
{
private:
  string InstMem[INSTMEMSIZE];
  int headInstMem;

public:
  string instruction;

  instMemory()
  {
    headInstMem = 0;
  }

  void writeInstMem(std::string data)
  {
    InstMem[headInstMem] = data;
    headInstMem++;
  }

  string readInstMem(int pos)
  {
    instruction = *(InstMem + pos);
    return *(InstMem + pos);
  }
};