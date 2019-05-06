#include <iostream>
#include <string>

using namespace std;

class loadBalancer
{
  private:
    string *Rd1lb;
    string *Rd2lb;

  public:
    int Rd1E1;
    int Rd2E1;
    int Rd1E2;
    int Rd2E2;
    int Rd1E3;
    int Rd2E3;
    int Rd1E4;
    int Rd2E4;
    int Rd1E5;
    int Rd2E5;
    int Rd1E6;
    int Rd2E6;
    int Rd1E7;
    int Rd2E7;
    int Rd1E8;
    int Rd2E8;

    loadBalancer(string *Rd1E, string *Rd2E)
    {
        Rd1lb = Rd1E;
        Rd2lb = Rd2E;
    }

    void balance(){
        Rd1E1 = stoi((*Rd1lb).substr(0,8));
        Rd2E1 = stoi((*Rd2lb).substr(0,8));
        Rd1E2 = stoi((*Rd1lb).substr(8,8));
        Rd2E2 = stoi((*Rd2lb).substr(8,8));
        Rd1E3 = stoi((*Rd1lb).substr(16,8));
        Rd2E3 = stoi((*Rd2lb).substr(16,8));
        Rd1E4 = stoi((*Rd1lb).substr(24,8));
        Rd2E4 = stoi((*Rd2lb).substr(24,8));
        Rd1E5 = stoi((*Rd1lb).substr(32,8));
        Rd2E5 = stoi((*Rd2lb).substr(32,8));
        Rd1E6 = stoi((*Rd1lb).substr(40,8));
        Rd2E6 = stoi((*Rd2lb).substr(40,8));
        Rd1E7 = stoi((*Rd1lb).substr(48,8));
        Rd2E7 = stoi((*Rd2lb).substr(48,8));
        Rd1E8 = stoi((*Rd1lb).substr(56,8));
        Rd2E8 = stoi((*Rd2lb).substr(56,8));
    }
};