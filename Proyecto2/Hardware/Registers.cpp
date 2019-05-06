#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Register
{
  private:
    string Reg;

  public:
    Register()
    {
        Reg = bitset<64>(0).to_string();
    }

    void setReg(string data)
    {
        Reg = data;
    }

    string getReg()
    {
        return Reg;
    }
};