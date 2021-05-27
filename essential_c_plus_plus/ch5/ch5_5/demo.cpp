#include <iostream>

#include "Fibonacci.h"

using namespace std;

vector<int> Fibonacci::_elems; // static数据成员只有唯一的一份实体，必须在程序代码文件中提供其清楚定义

// 非成员函数
ostream & operator<<(ostream &os, const num_sequence &ns){ // 重载output运算符
    return ns.print(os);
}


int main(){
    Fibonacci fib; // len=1 beg_pos=1
    cout << "fib: beginning at element 1 for 1 element: "
         << fib << endl;
    
    Fibonacci fib2(16); // len=16 beg_pos=1
    cout << "fib2: beginning at element 1 for 16 element: "
         << fib2 << endl;

    Fibonacci fib3(8, 12); // len=8 beg_pos=12
    cout << "fib3: beginning at element 12 for 8 element: "
         << fib3 << endl;   
    
}