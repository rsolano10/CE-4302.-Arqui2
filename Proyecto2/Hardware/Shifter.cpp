#include <iostream>
#include <string>

using namespace std;

class Shifter
{
  private:
    string *reg;
    int *flag;

    string shiftLeft()
    {
        (*reg).insert((*reg).begin(), (*reg)[8 - 1]);
        (*reg).erase((*reg).end() - 1);
    }

    string shiftRight()
    {
        (*reg).insert((*reg).end(), (*reg)[0]);
        (*reg).erase((*reg).begin());
    }

  public:
    int Result;
    Shifter(string *regstr,int *opFlag)
    {
        reg = regstr;
        flag = opFlag;
    }

    void operate(){
        if(*flag == 5){
            shiftLeft(); 
        }
        else if(*flag == 6){
            shiftRight();
        }
    }
};
