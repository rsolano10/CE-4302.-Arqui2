#include <iostream>
#include <string>
#include "Registers.cpp"

using namespace std;

class registersMem
{
private:
  int *Ra1d;
  int *Ra2d;
  int *flag;

public:
  Register *R1;
  Register *R2;
  Register *R3;
  Register *R4;
  Register *R5;
  Register *R6;
  Register *R7;
  Register *R8;
  Register *R9;
  Register *R10;
  string Rd1;
  string Rd2;

  registersMem(int *Ra1, int *Ra2, int *regWrite2)
  {
    R1 = new Register();
    R1->setReg("0000000000000000000000000000000000000000000000000000000000000001");
    R2 = new Register();
    R3 = new Register();
    R4 = new Register();
    R5 = new Register();
    R6 = new Register();
    R7 = new Register();
    R8 = new Register();
    R9 = new Register();
    R10 = new Register();
    Ra1d = Ra1;
    Ra2d = Ra2;
    flag = regWrite2;
  }

  void getRd1()
  {
    string temp;
    switch (*Ra1d)
    {
    case 1:
      temp = R1->getReg();
      Rd1 = temp;
      break;
    case 2:
      temp = R2->getReg();
      Rd1 = temp;
      break;
    case 3:
      temp = R3->getReg();
      Rd1 = temp;
      break;
    case 4:
      temp = R4->getReg();
      Rd1 = temp;
      break;
    case 5:
      temp = R5->getReg();
      Rd1 = temp;
      break;
    case 6:
      temp = R6->getReg();
      Rd1 = temp;
      break;
    case 7:
      temp = R7->getReg();
      Rd1 = temp;
      break;
    case 8:
      temp = R8->getReg();
      Rd1 = temp;
      break;
    case 9:
      temp = R9->getReg();
      Rd1 = temp;
      break;
    case 10:
      temp = R10->getReg();
      Rd1 = temp;
      break;
    default:
      break;
    }
  }

  void getRd2()
  {
    string temp;
    switch (*Ra2d)
    {
    case 1:
      temp = R1->getReg();
      Rd2 = temp;
      break;
    case 2:
      temp = R2->getReg();
      Rd2 = temp;
      break;
    case 3:
      temp = R3->getReg();
      Rd2 = temp;
      break;
    case 4:
      temp = R4->getReg();
      Rd2 = temp;
      break;
    case 5:
      temp = R5->getReg();
      Rd2 = temp;
      break;
    case 6:
      temp = R6->getReg();
      Rd2 = temp;
      break;
    case 7:
      temp = R7->getReg();
      Rd2 = temp;
      break;
    case 8:
      temp = R8->getReg();
      Rd2 = temp;
      break;
    case 9:
      temp = R9->getReg();
      Rd2 = temp;
      break;
    case 10:
      temp = R10->getReg();
      Rd2 = temp;
      break;
    default:
      break;
    }
  }

  void writeReg(int reg, string data){
    switch (reg)
    {
    case 1:
      R1->setReg(data);
      break;
    case 2:
      R2->setReg(data);
      break;
    case 3:
      R3->setReg(data);
      break;
    case 4:
      R4->setReg(data);
      break;
    case 5:
      R5->setReg(data);
      break;
    case 6:
      R6->setReg(data);
      break;
    case 7:
      R7->setReg(data);
      break;
    case 8:
      R8->setReg(data);
      break;
    case 9:
      R9->setReg(data);
      break;
    case 10:
      R10->setReg(data);
      break;
    default:
      break;
    }
  }

  string getRegMem(int reg){
    switch (reg)
    {
    case 1:
      return R1->getReg();
      break;
    case 2:
      return R2->getReg();
      break;
    case 3:
      return R3->getReg();
      break;
    case 4:
      return R4->getReg();
      break;
    case 5:
      return R5->getReg();
      break;
    case 6:
      return R6->getReg();
      break;
    case 7:
      return R7->getReg();
      break;
    case 8:
      return R8->getReg();
      break;
    case 9:
      return R9->getReg();
      break;
    case 10:
      return R10->getReg();
      break;
    default:
      break;
    }
  }
};