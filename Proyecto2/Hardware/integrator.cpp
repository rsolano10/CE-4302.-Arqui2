#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Integrator
{
  private:
    int *ALURes1,*ALURes2,*ALURes3,*ALURes4,*ALURes5,*ALURes6,*ALURes7,*ALURes8;
    int *ScalarFlag;
  public:
    string ALUResult;

    Integrator(int *res1,int *res2,int *res3,int *res4,int *res5,int *res6,int *res7,int *res8,int *ScalarE)
    {
        ALURes1 = res1;
        ALURes2 = res2;
        ALURes3 = res3;
        ALURes4 = res4;
        ALURes5 = res5;
        ALURes6 = res6;
        ALURes7 = res7;
        ALURes8 = res8;
        ScalarFlag = ScalarE;
    }

    void integrate(){
      cout << "**********Scalar Flag: " << *ScalarFlag <<  endl;
      if(*ScalarFlag == 0){
        ALUResult = bitset<8>(*ALURes8).to_string() + bitset<8>(*ALURes7).to_string() + bitset<8>(*ALURes6).to_string() + bitset<8>(*ALURes5).to_string() + bitset<8>(*ALURes4).to_string() + bitset<8>(*ALURes3).to_string() + bitset<8>(*ALURes2).to_string() + bitset<8>(*ALURes1).to_string();
      }
      else{
        cout << "entre";
        ALUResult = bitset<64>(*ALURes8).to_string();
      }
    }

};