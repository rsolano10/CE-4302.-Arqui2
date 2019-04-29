#include <iostream>
#include <fstream>

#include "DataMemory.cpp"
#include "InstMemory.cpp"
#include "PC.cpp"
/*#include "Registers.c"
#include "ALU.c"*/

#define INSTPATH "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Software/Compiler/text_out.txt"

dataMemory *dmem; // data mem
instMemory *imem; // instruction mem
PC *pc;

/* Load instructions inside imem */
void loadInst(){
    std::ifstream file(INSTPATH);
    std::string str; 
    while (std::getline(file, str))
    {
        imem->writeInstMem(str);
    }
}

int main()
{
    dmem = new dataMemory();
    imem = new instMemory();
    pc = new PC();

    loadInst();

    /*dataMemory *mem = new dataMemory();
    mem->writeDataMem(1);
    int data = mem->readDataMem(0);
    cout << data << '\n';
    string inst = "00000000000000000000000100100011";
    instMemory *imem = new instMemory();
    imem->writeInstMem(inst);
    string data2 = imem->readInstMem(0);
    for(int i = 0; i < 32; i++)
    {
        cout << data2[i] << '\n';
    }*/
    
    
}