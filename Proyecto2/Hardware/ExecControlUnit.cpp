#include <iostream>
#include <string>

using namespace std;

class execControlUnit
{
    private:
        int *flag;
    
    public:
    int regWrite2;
    int ALUControlD; /* ALUControl --> 1 = add, 2 = sub, 3 = mult, 4 = xor*/


    execControlUnit(int *ALUflag){
        flag = ALUflag;
    }
    
    void getControlFlags(){
        if(*flag == 4){
            regWrite2 = 1;  
        } /*continue with else ifs*/
        if(*flag == 1){
            regWrite2 = 1;  
        } /*continue with else ifs*/
        if(*flag == 2){
            regWrite2 = 1;  
        } /*continue with else ifs*/
        if(*flag == 3){
            regWrite2 = 1;  
        } /*continue with else ifs*/
    }
};