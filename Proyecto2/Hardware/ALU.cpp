#include <iostream>

using namespace std;

class ALU
{
  private:
    int *op1;
    int *op2;
    int *flag;

  public:
    int Result;
    ALU(int *rd1, int *rd2,int *opFlag)
    {
        op1 = rd1;
        op2 = rd2;
        flag = opFlag;
    }

    int sum()
    {
        Result = ((*op1) + (*op2));
    }

    int sub()
    {
        Result = ((*op1) - (*op2));
    }

    int mult()
    {
        Result = ((*op1) * (*op2));
    }

    int xori()
    {
        Result = ((*op1) ^ (*op2));
    }
};
