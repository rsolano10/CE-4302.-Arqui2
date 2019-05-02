#include <iostream>

using namespace std;

class Register
{
  private:
    int Reg;

  public:
    Register()
    {
        Reg = 0;
    }

    void setReg(int data)
    {
        Reg = data;
    }

    int getReg()
    {
        return Reg;
    }
};