#include <vector>
#include <iostream>

// #include "LessThan.h"
#include "LessThanPred.h"

using namespace std;

class StringLen{
public:
    bool operator()(const string &s1, const string &s2) { return s1.size()<s2.size(); }
private:
};

int main(){
    // LessThan<int> lti(1024);
    // LessThan<string> lts("Pooh");

    LessThanPred<int> ltpi(1024);
    LessThanPred<string, StringLen> ltps("Pooh");
}