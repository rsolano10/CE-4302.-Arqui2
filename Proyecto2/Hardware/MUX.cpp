#include <iostream>

using namespace std;

class Mux
{
  private:
    bool *OpFlag;
    int *Op1;
    int *Op2;
  public:
    Mux(bool *Flag, int *data1, int *data2)
    {
        OpFlag = Flag;
        Op1 = data1;
        Op2 = data2;
    }

    int getData(){
        if(*OpFlag){
            return *Op1;
        }
        else{
            return *Op2;
        }
    }

};