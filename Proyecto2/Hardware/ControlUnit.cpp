#include <iostream>
#include <string>

using namespace std;

class controlUnit
{
    private:
    string *Op;
    int *Rd;
    
    public:
    int ALUControlD; /* ALUControl --> 1 = add, 2 = sub, 3 = mult, 4 = xor*/
    int RegWriteD; /* 0 = read, 1 = write*/
    int MemWriteD; /* 0 = read, 1 = write*/

    controlUnit(string *Opstr,int *Rdstr){
        Op = Opstr;
        Rd = Rdstr;
    }
    
    void getControlFlags(){
        if(*Op == "0000"){
            ALUControlD = 4;
            RegWriteD = 0;
            MemWriteD = 1;
        } /*continue with else ifs*/
    }
};