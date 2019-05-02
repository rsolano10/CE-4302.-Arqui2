#include <iostream>
#include <unistd.h>


using namespace std;

class Clock
{
  private:
    unsigned int frec = 0.02; // 50KHz
    bool state;
    bool reset;

    void init_aux(){
        while(!reset){
            state = !state;
            usleep(frec);
        }
    }

  public:
    Clock(){
        state = false;
        reset = true;
    }

    void init(){
        reset = false;
        init_aux();
    }

    void setFrec(int f){
        frec = f;
    }

    unsigned int getFrec(){
        return frec;
    }

    void setReset(bool resetState){
        reset = resetState;
    }

    bool getReset(){
        return reset;
    }

    void setState(bool State){
        reset = State;
    }

    bool getState(){
        return state;
    }
};
