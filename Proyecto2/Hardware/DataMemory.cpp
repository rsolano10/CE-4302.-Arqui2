#include <iostream>
#include <string>
#include <bitset>
#define DATAMEMSIZE 5000000

using namespace std;

class dataMemory
{
  private:
    int dataMem[DATAMEMSIZE];
    int headDataMem;
    string *ALUinput;
    int *flag;
  
  public:
    int *dirInput;
    string memResult;
    dataMemory(string *ALUResult, int *memWriteM, int *bdir){
      headDataMem = 0;
      ALUinput = ALUResult;
      dirInput = bdir;
      flag = memWriteM;
    }

    void writeDataMem(int data)
    {
        cout << "dirinput: " << *dirInput << endl;
        cout << "data mem: " << data << endl;
        dataMem[(*dirInput)] = (int) data;
    }

    int readDataMem()
    {
        cout << "(*dirInput): " << (*dirInput) << endl;
        cout << "data mem: " << dataMem[(*dirInput)] << endl;
        return *(dataMem + (*dirInput));
    }

    void uploadImage(int data){
      dataMem[headDataMem] = data;
      headDataMem++;
    }

    int getPixel(int pos){
      return dataMem[pos];
    }

    void operate(){
      if(*flag == 1){
        memResult = *ALUinput;
        writeDataMem(stoi((*ALUinput).substr(56,8),nullptr,2));
        (*dirInput)++;
        writeDataMem(stoi((*ALUinput).substr(48,8),nullptr,2));
        (*dirInput)++;
        writeDataMem(stoi((*ALUinput).substr(40,8),nullptr,2));
        (*dirInput)++;
        writeDataMem(stoi((*ALUinput).substr(32,8),nullptr,2));
        (*dirInput)++;
        writeDataMem(stoi((*ALUinput).substr(24,8),nullptr,2));
        (*dirInput)++;
        writeDataMem(stoi((*ALUinput).substr(16,8),nullptr,2));
        (*dirInput)++;
        writeDataMem(stoi((*ALUinput).substr(8,8),nullptr,2));
        (*dirInput)++;
        writeDataMem(stoi((*ALUinput).substr(0,8),nullptr,2));
      }
      else{
        string m1 = bitset<8>(readDataMem()).to_string();
        (*dirInput)++;
        string m2 = bitset<8>(readDataMem()).to_string();
        (*dirInput)++;
        string m3 = bitset<8>(readDataMem()).to_string();
        (*dirInput)++;
        string m4 = bitset<8>(readDataMem()).to_string();
        (*dirInput)++;
        string m5 = bitset<8>(readDataMem()).to_string();
        (*dirInput)++;
        string m6 = bitset<8>(readDataMem()).to_string();
        (*dirInput)++;
        string m7 = bitset<8>(readDataMem()).to_string();
        (*dirInput)++;
        string m8 = bitset<8>(readDataMem()).to_string();
        memResult = m8 + m7 + m6 + m5 + m4 + m3 + m2 + m1;
        cout << "memout: " << memResult << endl;
      }
    }

    void xorimg(){
      for(int i = 0 ; i < 640000 ; i++){
        dataMem[i] = (dataMem[i] ^ 1);
      }
    }
};