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
    string Imm;
    string Op;
    string isRegOp;

    fetchReg(string *instruction)
    {
        inst = instruction;
    }

    string getCond()
    {
        return (*inst).substr(0, 4);
    }

    string getOp()
    {
        Op = (*inst).substr(4, 4);
        return (*inst).substr(4, 4);
    }

    string getRa1()
    {
        isRegOp = (*inst).substr(8, 1);
        if (isRegOp == "0")
        {
            if (Op == "0000" || Op == "0001" || Op == "0010" || Op == "0011")
            { //xor
                Ra1 = std::stoi((*inst).substr(20, 4), nullptr, 2);
                return (*inst).substr(20, 4);
            }
        }
        else
        {
            if (Op == "0000" || Op == "0001" || Op == "0010" || Op == "0011")
            { //xor
                Ra1 = std::stoi((*inst).substr(20, 4), nullptr, 2);
                return (*inst).substr(20, 4);
            }
            else if(Op == "0101"){
                Ra1 = 0;
                return "0000";
            }
        }
    }

    string getRa2()
    {
        isRegOp = (*inst).substr(8, 1);
        if (isRegOp == "0")
        {
            if (Op == "0000" || Op == "0001" || Op == "0010" || Op == "0011")
            {
                Ra2 = std::stoi((*inst).substr(24, 4), nullptr, 2);
                return (*inst).substr(24, 4);
            }
        }
        else
        {
            if (Op == "0000" || Op == "0001" || Op == "0010" || Op == "0011")
            {
                Ra2 = 0;
                return "0000";
            }
            else if(Op == "0101"){
                Ra2 = 0;
                return "0000";
            }
        }
    }

    string getRd()
    {
        isRegOp = (*inst).substr(8, 1);
        if (isRegOp == "0")
        {
            if (Op == "0000" || Op == "0001" || Op == "0010" || Op == "0011")
            {
                Rd = std::stoi((*inst).substr(28, 4), nullptr, 2);
                return (*inst).substr(28, 4);
            }
        }
        else
        {
            if (Op == "0000" || Op == "0001" || Op == "0010" || Op == "0011")
            {
                Rd = std::stoi((*inst).substr(16, 4), nullptr, 2);
                return (*inst).substr(16, 4);
            }
            else if(Op == "0101"){
                Rd = std::stoi((*inst).substr(20, 4), nullptr, 2);
                return (*inst).substr(20, 4);
            }
        }
    }
    string getImm()
    {
            Imm =  (*inst).substr(24, 8);
            return (*inst).substr(24, 8);
    }

    string getisImm(){
        return (*inst).substr(8, 1);
    }
};