#include <iostream>

using namespace std;

class ALU
{
  private:
    int *op1;
    int *op2;
    int *flag;

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

  public:
    int Result;
    ALU(int *rd1, int *rd2,int *opFlag)
    {
        op1 = rd1;
        op2 = rd2;
        flag = opFlag;
    }

    void operate(){
        if(*flag == 4){
            xori(); 
        }
    }
};
