#include <iostream>
#include <typeinfo>

#include "../ch5_7/Fibonacci.h"

using namespace std;

inline void display(ostream &os, const num_sequence &ns, int pos){
    os << "The element at position " << pos << " for the "
       << ns.what_am_i() << " sequence is " << ns.elem(pos) << endl; // 调用了2个虚函数what_am_i() 和 elem()
}

int main(){
    const int pos = 8;

    Fibonacci fib; // len=1 beg_pos=1
    display(cout, fib, pos);

    num_sequence *ps = &fib;
    // ps->Fibonacci::gen_elems(64);
    
    if(typeid(*ps) == typeid(Fibonacci)){
        cout << "ps point to a Fibonacci object!\n";
        Fibonacci *pf = static_cast<Fibonacci*>(ps); // 无条件转换 静态转换
        pf->gen_elems(64); // Jane: gen_elems是protected 提示不可访问？
    }

    if(Fibonacci *pf = dynamic_cast<Fibonacci*>(ps)) // 有条件转换 动态转换
        pf->gen_elems(64); // Jane: gen_elems是protected 提示不可访问？
    
}