#include <iostream>

#include "Fibonacci.h"

using namespace std;

int main(){
    Fibonacci<8> fib1; // len=8, beg_pos=1
    cout << "fib1: " << fib1 << endl;

    Fibonacci<8,8> fib2; // len=8, beg_pos=8
    cout << "fib2: " << fib2 << endl;

    Fibonacci<12,8> fib3; // len=12, beg_pos=8
    cout << "fib3: " << fib3 << endl;
}