#include <iostream>

using namespace std;

class PC
{
  private:
    int PCReg;

  public:
    PC()
    {
        PCReg = -1;
    }

    void setPC(int pos)
    {
        PCReg = pos;
    }

    int getPC()
    {
        return PCReg;
    }
};