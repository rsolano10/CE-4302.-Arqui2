#include <iostream>
#include <string>

using namespace std;

class binManager
{
    public :
        int bintodec(string bin){
            int i = std::stoi(bin, nullptr, 2);
            return i;
        }
};