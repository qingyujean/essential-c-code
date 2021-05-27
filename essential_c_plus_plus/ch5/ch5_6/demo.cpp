#include <iostream>

#include "../ch5_5/Fibonacci.h"

using namespace std;

inline void display(ostream &os, const num_sequence &ns, int pos){
    os << "The element at position " << pos << " for the "
       << ns.what_am_i() << " sequence is " << ns.elem(pos) << endl; // 调用了2个虚函数what_am_i() 和 elem()
}

int main(){
    const int pos = 8;

    Fibonacci fib; // len=1 beg_pos=1
    display(cout, fib, pos);

    Fibonacci fib2(8); // len=8 beg_pos=1
    cout << "fib: " << fib2 << endl;
}