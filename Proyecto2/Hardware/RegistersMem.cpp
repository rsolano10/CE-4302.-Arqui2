#include <iostream>
#include "Registers.cpp"

using namespace std;

class registersMem
{
private:
  int *Ra1d;
  int *Ra2d;

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
  int Rd1;
  int Rd2;

  registersMem(int *Ra1, int *Ra2)
  {
    R1 = new Register();
    R1->setReg(1);
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
  }

  void getRd1()
  {
    int temp;
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
    int temp;
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
};