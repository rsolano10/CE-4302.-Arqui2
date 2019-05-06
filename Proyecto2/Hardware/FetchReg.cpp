#include <iostream>
#include <string>

using namespace std;

class fetchReg
{
  private:
    string *inst;

  public:
    int Ra1;
    int Ra2;
    int Rd;
    string Op;

    fetchReg(string *instruction)
    {
        inst = instruction;
    }

    string getCond(){
        return (*inst).substr(0,4);
    }

    string getOp(){ 
        Op = (*inst).substr(4,4);
        return (*inst).substr(4,4);
    }

    string getRa1(){
        if(Op == "0000"){ //xor
            Ra1 = std::stoi((*inst).substr(20,4), nullptr, 2);
            return (*inst).substr(20,4);
        }
        else if(Op == "0101"){ //mov imm
            Ra1 = std::stoi((*inst).substr(20,4), nullptr, 2);
            return (*inst).substr(20,4);
        }
    }

    string getRa2(){
        if(Op == "0000"){
            Ra2 = std::stoi((*inst).substr(24,4), nullptr, 2);
            return (*inst).substr(24,4);
        }
    }

    string getRd(){
        if(Op == "0000"){
            Rd = std::stoi((*inst).substr(28,4), nullptr, 2);
            return (*inst).substr(28,4);
        }
    }
};