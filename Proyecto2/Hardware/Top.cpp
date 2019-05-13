#include <iostream>
#include <fstream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <bitset>

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
#include "WriteReg.cpp"
#include "ExecControlUnit.cpp"
#include "loadBalancer.cpp"
#include "integrator.cpp"

#define INSTPATH "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Software/Compiler/text_out.txt"
#define IMGPATHI "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Documentos/Imagenes/input.pgm"
#define IMGPATHO "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Documentos/Imagenes/output.pgm"
#define MEMPATHI "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Documentos/Imagenes/input_data.txt"
#define MEMPATHO "/home/rodolfo/git/CE-4302.-Arqui2/Proyecto2/Documentos/Imagenes/output_data.txt"
#define MAXINST 40002

dataMemory *dmem;     // data mem
instMemory *imem;     // instruction mem
PC *pc;               //PC
registersMem *regmem; //Registers memory
fetchReg *freg;       //Fetch register
ALU *alu;             //ALU
ALU *alu1;            //ALU
ALU *alu2;            //ALU
ALU *alu3;            //ALU
ALU *alu4;            //ALU
ALU *alu5;            //ALU
ALU *alu6;            //ALU
ALU *alu7;            //ALU
execReg *ereg;        //execute register
controlUnit *cunit;   // control unit
memReg *mreg;         // register memory
unsigned char *image; // image reference
Clock *clk;           //system clock
writeReg *wreg;       //write back register
execControlUnit *ecu; //secundary control unit in execution cycle.
int *_regFlag;
mutex system_mutex;     //clock mutex
loadBalancer *balancer; //ALU load balancer
Integrator *integrator; //ALU results integrator

/* Load instructions inside imem */
void loadInst()
{
    std::ifstream file(INSTPATH);
    std::string str;
    while (std::getline(file, str))
    {
        imem->writeInstMem(str);
    }
    cout << "instructions uploaded to mem!" << endl;
}

void loadData()
{
    readImage(IMGPATHI, &image);
    for (int i = 0; i < totalPixels; i++)
    {
        dmem->uploadImage((int)image[i]);
    }
    cout << "image uploaded to mem!" << endl;
}

void initClock()
{
    clk->init();
}

void fetch()
{
    /*----------------fetch-----------------*/
    system_mutex.lock();
    try
    {
        printStep("Fetch");
        pc->setPC(pc->getPC() + 1); // se incrementa el PC
        printint("PC", pc->getPC());

        imem->readInstMem(pc->getPC()); //lee la instruccion correspondiente a PC
        printstring("Instruction", imem->readInstMem(pc->getPC()));
        printstring("OP Code", freg->getOp());                       // actualiza Op en el registro del fetch
        printstring("Ra1 fetch register value", freg->getRa1());     // actualiza Op en el registro del fetch
        printstring("Ra2 fetch register value", freg->getRa2());     // actualiza Op en el registro del fetch
        printstring("Rd fetch register value", freg->getRd());       // actualiza Op en el registro del fetch
        printstring("Imm fetch register value", freg->getImm());     // actualiza Op en el registro del fetch
        printstring("isImm fetch register value", freg->getisImm()); // actualiza Op en el registro del fetch
    }
    catch (exception e)
    {
    }
    system_mutex.unlock();
}

void decode()
{
    system_mutex.lock();
    printStep("Decode");
    cunit->getControlFlags(); // set Control flags
    printint("ALU flag control unit", cunit->ALUControlD);
    printint("Reg mem. flag control unit", cunit->RegWriteD);
    printint("Data mem. flag control unit", cunit->MemWriteD);
    printint("Scalar flag control unit", cunit->Scalar);
    //TODO: cambiar registros para leer 8 datos en vez de 1 solo int
    //for read only
    regmem->getRd1(); //get Rd1 value
    regmem->getRd2(); //get Rd2 value
    printstring("Reg mem Rd1", (regmem->Rd1));
    printstring("Reg mem Rd2", (regmem->Rd2));

    //execReg automatic take update values
    printstring("exec reg Rd1E", (*ereg->Rd1E));
    printstring("exec reg Rd2E", (*ereg->Rd2E));
    printint("exec reg ALUControlE", (*ereg->ALUControlE));
    printint("exec reg RegWriteE", (*ereg->RegWriteE));
    printint("exec reg MemWriteE", (*ereg->MemWriteE));
    printint("exec reg memToReg", (*ereg->memtoRegE));
    printint("exec reg Rd", (*ereg->RdE));
    system_mutex.unlock();
}

void exec()
{
    system_mutex.lock();
    printStep("Execute");
    balancer->balance();
    //balancer values
    printint("balancer Rd1E8", balancer->Rd1E8);
    printint("balancer Rd2E8", balancer->Rd2E8);
    printint("balancer Rd1E7", balancer->Rd1E7);
    printint("balancer Rd2E7", balancer->Rd2E7);
    printint("balancer Rd1E6", balancer->Rd1E6);
    printint("balancer Rd2E6", balancer->Rd2E6);
    printint("balancer Rd1E5", balancer->Rd1E5);
    printint("balancer Rd2E5", balancer->Rd2E5);
    printint("balancer Rd1E4", balancer->Rd1E4);
    printint("balancer Rd2E4", balancer->Rd2E4);
    printint("balancer Rd1E3", balancer->Rd1E3);
    printint("balancer Rd2E3", balancer->Rd2E3);
    printint("balancer Rd1E2", balancer->Rd1E2);
    printint("balancer Rd2E2", balancer->Rd2E2);
    printint("balancer Rd1E1", balancer->Rd1E1);
    printint("balancer Rd2E1", balancer->Rd2E1);

    alu->operate();
    alu1->operate();
    alu2->operate();
    alu3->operate();
    alu4->operate();
    alu5->operate();
    alu6->operate();
    alu7->operate();
    printint("ALU result", alu->Result);
    printint("ALU1 result", alu1->Result);
    printint("ALU2 result", alu2->Result);
    printint("ALU3 result", alu3->Result);
    printint("ALU4 result", alu4->Result);
    printint("ALU5 result", alu5->Result);
    printint("ALU6 result", alu6->Result);
    printint("AL7 result", alu7->Result);

    integrator->integrate();

    printstring("integrator result", (integrator->ALUResult));

    ecu->getControlFlags();

    //memReg automatic take update values
    printstring("mem reg ALUResultM", (*mreg->ALUResultM));
    printint("mem reg RegWriteM", (*mreg->RegWriteM));
    printint("mem reg MemWriteEM", (*mreg->MemWriteM));
    printint("mem reg Rd", (*mreg->RdM));
    printint("exec reg memToReg", (*mreg->memToRegM));
    system_mutex.unlock();
}

void mem()
{
    system_mutex.lock();
    printStep("Memory");
    dmem->operate();

    printstring("Write-back reg ALUResultM", (*wreg->ALUdata));
    printint("Write-back reg MemWriteW", (*wreg->MemWriteW));
    printint("Write-back reg RegWriteW", (*wreg->RegWriteW));

    wreg->updateFlags();

    printint("write reg memToReg", (*wreg->MemWriteW));
    printint("Write-back reg RegWrite2", (*wreg->regWrite2));
    printstring("Write-back data to write", (wreg->writedata));
    system_mutex.unlock();
}

void writeBack()
{
    system_mutex.lock();
    printStep("Write Back");
    printint("Register to write", *wreg->RdW);
    regmem->writeReg(*wreg->RdW, wreg->writedata);
    cout << "mem space to read: " << *wreg->RdW <<endl;
    //printstring("Write-back reg Read", regmem->getRegMem(*wreg->RdW));
    system_mutex.unlock();
}

void loadMenu()
{
    cout << "------ Main Menu ------" << endl;
    cout << "--> 1. manual clock" << endl;
    cout << "--> 2. auth clock" << endl;
    cout << "Number: ";
}

int main()
{
    /*Hardware instantiate*/
    clk = new Clock();
    pc = new PC();
    imem = new instMemory();
    freg = new fetchReg(&(imem->instruction));
    regmem = new registersMem(&(freg->Ra1), &(freg->Ra2), &(*_regFlag));
    cunit = new controlUnit(&(freg->Op), &(freg->Rd), &(freg->isRegOp));
    ereg = new execReg(&(cunit->ALUControlD), &(cunit->RegWriteD), &(cunit->MemWriteD), &(regmem->Rd1), &(regmem->Rd2), &(cunit->memtoReg), &(*cunit->Rd), &(freg->Imm), &(*cunit->isImm),&(freg->LdSt),&cunit->Scalar);
    ecu = new execControlUnit(&(*ereg->ALUControlE));
    balancer = new loadBalancer(&(*ereg->Rd1E), &(*ereg->Rd2E), &(*ereg->isImmE), &(*ereg->ImmE),&(*ereg->LDSTE),&(*ereg->ScalarE));
    alu = new ALU(&(balancer->Rd1E8), &(balancer->Rd2E8), &(*ereg->ALUControlE));
    alu1 = new ALU(&(balancer->Rd1E7), &(balancer->Rd2E7), &(*ereg->ALUControlE));
    alu2 = new ALU(&(balancer->Rd1E6), &(balancer->Rd2E6), &(*ereg->ALUControlE));
    alu3 = new ALU(&(balancer->Rd1E5), &(balancer->Rd2E5), &(*ereg->ALUControlE));
    alu4 = new ALU(&(balancer->Rd1E4), &(balancer->Rd2E4), &(*ereg->ALUControlE));
    alu5 = new ALU(&(balancer->Rd1E3), &(balancer->Rd2E3), &(*ereg->ALUControlE));
    alu6 = new ALU(&(balancer->Rd1E2), &(balancer->Rd2E2), &(*ereg->ALUControlE));
    alu7 = new ALU(&(balancer->Rd1E1), &(balancer->Rd2E1), &(*ereg->ALUControlE));
    integrator = new Integrator(&alu->Result, &alu1->Result, &alu2->Result, &alu3->Result, &alu4->Result, &alu5->Result, &alu6->Result, &alu7->Result,&(*ereg->ScalarE));
    mreg = new memReg(&(ecu->regWrite2), &(*ereg->MemWriteE), &(integrator->ALUResult), &(*ereg->memtoRegE), &(*ereg->RdE));
    dmem = new dataMemory(&(integrator->ALUResult), &(*mreg->MemWriteM),&(balancer->bdir));
    wreg = new writeReg(&(*mreg->RegWriteM), &(*mreg->MemWriteM), &(integrator->ALUResult), &(dmem->memResult), &(*_regFlag), &(*mreg->memToRegM), &(*mreg->RdM));

    thread clock50Hz(initClock); // init clock in a thread

    loadInst(); // load instructions into memory
    loadData(); // load image into memory
    writeMatrix(MEMPATHI,&image);

    //clock choice
    loadMenu();
    int choice;
    cin >> choice;
    int iterations = 0;

    while (true)
    {
        if (choice == 1)
        { //clk->getState()){
            /*cout << "****************************************" << endl;
            int input;
            cin >> input;
            if (input == 1)
            {
                writeImage(IMGPATHO, &image);
            }
            else
            {
                thread tfetch(fetch);
                thread tdecode(decode);
                thread texec(exec);
                thread tmem(mem);
                thread twrite(writeBack);
                tfetch.join();
                tdecode.join();
                texec.join();
                tmem.join();
                twrite.join();
            }*/
            cout << "****************************************" << endl;
            cin.get();
            fetch();
            decode();
            exec();
            mem();
            writeBack();
        }
        else if (choice == 2)
        {
            cout << "****************************************" << endl;
            fetch();
            decode();
            exec();
            mem();
            writeBack();
            if(pc->getPC() == MAXINST){
                unsigned char *img2;
                img2 = (unsigned char*)malloc(numberOfColumns*numberOfRows);
                
                //cout << "pixel: " << dmem->getPixel(10000) << endl;
                for (int i = 0; i < totalPixels; i++)
                {
                    img2[i] = dmem->getPixel(i);
                }
                
                writeImage(IMGPATHO,&img2);
                writeMatrix(MEMPATHI,&image);
                writeMatrix(MEMPATHO,&img2);
                break;
            }
        }
        else if (choice == 3)
        {
            unsigned char *img2;
            img2 = (unsigned char*)malloc(numberOfColumns*numberOfRows);
            
            //cout << "pixel: " << dmem->getPixel(10000) << endl;
            for (int i = 0; i < totalPixels; i++)
            {
                img2[i] = dmem->getPixel(i);
            }
            
            writeImage(IMGPATHO,&img2);
            break;
        }
    }

    clk->setReset(true); // termina el reloj
}