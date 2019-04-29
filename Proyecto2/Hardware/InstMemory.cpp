#include <iostream>
#include <string>
#define INSTMEMSIZE 1000

using namespace std;
class instMemory
{
  private:
    string InstMem[INSTMEMSIZE];
    int headInstMem;

  public:
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
        return *(InstMem + pos);
    }
};