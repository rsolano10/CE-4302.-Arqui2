#include <iostream>
#include <string>

using namespace std;

class controlUnit
{
    private:
    string *Op;
    
    
    public:
    int ALUControlD; /* ALUControl --> 1 = add, 2 = sub, 3 = mult, 4 = xor*/
    int RegWriteD; /* 0 = read, 1 = write*/
    int MemWriteD; /* 0 = read, 1 = write*/
    int memtoReg; /* 0 = read, 1 = write*/
    int *Rd;
    int Scalar;
    string *isImm;

    controlUnit(string *Opstr,int *Rdstr, string *ImmOp){
        Op = Opstr;
        Rd = Rdstr;
        isImm = ImmOp;
    }
    
    void getControlFlags(){
        if(*Op == "0000"){
            ALUControlD = 4;
            RegWriteD = 0;
            MemWriteD = 0;
            memtoReg = 0;
            Scalar = 0;
        } 
        else if(*Op == "0001"){
            ALUControlD = 1;
            RegWriteD = 0;
            MemWriteD = 0;
            memtoReg = 0;
            if(*Rd == 0 || *Rd == 1){
                Scalar = 1;
            }
            else{
                Scalar = 0;
            }
        }
        else if(*Op == "0010"){
            ALUControlD = 2;
            RegWriteD = 0;
            MemWriteD = 0;
            memtoReg = 0;
            if(*Rd == 0 || *Rd == 1){
                Scalar = 1;
            }
            else{
                Scalar = 0;
            }
        }
        else if(*Op == "0011"){
            ALUControlD = 3;
            RegWriteD = 0;
            MemWriteD = 0;
            memtoReg = 0;
            Scalar = 0;
        }
        else if(*Op == "0101"){
            ALUControlD = 0;
            RegWriteD = 0;
            MemWriteD = 0;
            memtoReg = 0;
            Scalar = 0;
        }
        else if(*Op == "1010"){
            ALUControlD = 0;
            RegWriteD = 0;
            MemWriteD = 0;
            memtoReg = 1;
            Scalar = 0;
        }
        else if(*Op == "1011"){
            ALUControlD = 0;
            RegWriteD = 0;
            MemWriteD = 1;
            memtoReg = 0;
            Scalar = 0;
        }
    }
};