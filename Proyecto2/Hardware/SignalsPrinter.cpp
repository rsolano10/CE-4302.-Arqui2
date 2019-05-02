#include <iostream>
#define LOGON true

using namespace std;

void printStep(string step){
    if(LOGON)
        cout << "---------------"+step+"--------------------" << endl;
}

void printint(string signal, int value){
    if (LOGON)
        cout << "--> " << signal << ": " << value << endl;
}

void printstring(string signal, string value){
    if (LOGON)
        cout << "--> " << signal << ": " << value << endl;
}