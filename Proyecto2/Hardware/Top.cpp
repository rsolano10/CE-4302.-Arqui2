#include <iostream>
#include <fstream>
#include <thread>
#include <unistd.h>

#include "DataMemory.cpp"
#include "InstMemory.cpp"
#include "PC.cpp"
#include "RegistersMem.cpp"
#include "ALU.cpp"
#include "MUX.cpp"
#include "FetchReg.cpp"
#include "ExecReg.cpp"
#include "ControlUnit.cpp"
#include "MemReg.cpp"
#include "../Software/ImgManager/ImgManager.cpp"
#include "Clock.cpp"
#include "SignalsPrinter.cpp"

#define INSTPATH "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Software/Compiler/text_out.txt"
#define IMGPATHI "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Software/ImgManager/big.ppm"
#define IMGPATHO "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Software/ImgManager/out.pgm"

dataMemory *dmem; // data mem
instMemory *imem; // instruction mem
PC *pc; //PC
registersMem *regmem; //Registers memory
fetchReg *freg; //Fetch register
ALU *alu; //ALU
execReg *ereg; //execute register
controlUnit *cunit; // control unit
memReg *mreg; // register memory
unsigned char *image; // image reference
Clock *clk; //system clock

/* Load instructions inside imem */
void loadInst(){
    std::ifstream file(INSTPATH);
    std::string str; 
    while (std::getline(file, str))
    {
        imem->writeInstMem(str);
    }
    cout << "instructions uploaded to mem!" << endl;
}

void loadData(){
    readImage(IMGPATHI,&image);
    for (int i = 0; i < totalPixels; i++)
    {
        dmem->uploadImage((int)image[i]);
    }
    cout << "image uploaded to mem!" << endl;
}

void initClock(){
    clk->init();
}

int main()
{
    /*Hardware instantiate*/
    clk = new Clock();
    pc = new PC();
    imem = new instMemory();
    freg = new fetchReg(&(imem->instruction));
    regmem = new registersMem(&(freg->Ra1),&(freg->Ra2));
    cunit = new controlUnit(&(freg->Op),&(freg->Rd));
    ereg = new execReg(&(cunit->ALUControlD),&(cunit->RegWriteD),&(cunit->MemWriteD),&(regmem->Rd1),&(regmem->Rd2));
    alu = new ALU(&(*ereg->Rd1E),&(*ereg->Rd2E),&(*ereg->ALUControlE));
    mreg = new memReg(&(*ereg->ALUControlE),&(*ereg->RegWriteE),&(*ereg->MemWriteE),&(alu->Result));
    dmem = new dataMemory(&(alu->Result),&(*ereg->Rd2E));

    thread clock50Hz (initClock); // init clock in a thread

    loadInst(); // load instructions into memory
    loadData(); // load image into memory
    
    bool test = true;
    while(test){
        if(clk->getState()){

            /*----------------fetch-----------------*/
            printStep("Fetch");
            pc->setPC(pc->getPC() + 1); // se incrementa el PC
            printint("PC",pc->getPC());
            
            imem->readInstMem(pc->getPC()); //lee la instruccion correspondiente a PC
            printstring("Instruction", imem->readInstMem(pc->getPC()));
            printstring("OP Code",freg->getOp()); // actualiza Op en el registro del fetch
            printstring("Ra1 fetch register value",freg->getRa1()); // actualiza Op en el registro del fetch
            printstring("Ra2 fetch register value",freg->getRa2()); // actualiza Op en el registro del fetch
            printstring("Rd fetch register value",freg->getRd()); // actualiza Op en el registro del fetch

            /*----------------decode-----------------*/
            printStep("Decode");
            cunit->getControlFlags(); // set Control flags
            printint("ALU flag control unit",cunit->ALUControlD);
            printint("Reg mem. flag control unit",cunit->RegWriteD);
            printint("Data mem. flag control unit",cunit->MemWriteD);
            /*TODO: agregar logica de writemem para controlar bandera de r/w de memoria de registros*/
            /*TODO: cambiar registros para leer 8 datos en vez de 1 solo int*/
            //for read only
            regmem->getRd1(); //get Rd1 value
            regmem->getRd2(); //get Rd2 value
            printint("Reg mem Rd1",(regmem->Rd1));
            printint("Reg mem Rd2",(regmem->Rd2));
            
            /*execReg auth take update values*/
            printint("exec reg Rd1E",(*ereg->Rd1E));
            printint("exec reg Rd2E",(*ereg->Rd2E));
            printint("exec reg ALUControlE",(*ereg->ALUControlE));
            printint("exec reg RegWriteE",(*ereg->RegWriteE));
            printint("exec reg MemWriteE",(*ereg->MemWriteE));



            

            clk->setReset(true); // termina el reloj

            clock50Hz.join(); // sincroniza los thread

            test = false;
        }
    }

}