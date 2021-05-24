#include <iostream>

#include "Triangular.h"

using namespace std;

Triangular::Triangular(){ // default 构造器
    _length = 1;
    _begin_pos = 1;
    _next = 0;
}
/* 或者在定义时写成:Triangular(int len=1, int bp=1); 也是default构造器
*/

Triangular::Triangular(int len){
    _length = len>0 ? len : 1;
    _begin_pos = 1;
    _next = 0;
}
/*
Triangular::Triangular(int len, int bp){
    _length = len>0 ? len : 1;
    _begin_pos = bp>0 ? bp : 1;
    _next = _begin_pos-1;
}
*/
// Member initialization list(成员初始化列表)
// Triangular::Triangular(const Triangular &rhs): _length(rhs._length), _begin_pos(rhs._begin_pos), _next(rhs._next){}

Triangular::Triangular(int len, int bp): _name("Triangular"){ // Member initialization list(成员初始化列表) _name
    _length = len>0 ? len : 1;
    _begin_pos = bp>0 ? bp : 1;
    _next = _begin_pos-1;
}

void Triangular::myprint(){
    cout << _length << ' '
         << _begin_pos << ' '
         << _next << ' '
         << _name << endl;
}


int main(){
    Triangular tri1;
    tri1.myprint(); // 1 1 0

    Triangular tri2(12);
    tri2.myprint(); // 12 1 0

    Triangular tri3(8, 3);
    tri3.myprint(); // 8, 3, 2

    // 以下2个 在有Triangular::Triangular(const Triangular &rhs): _length(rhs._length), _begin_pos(rhs._begin_pos), _next(rhs._next){}
    // 时调用的是此构造函数，即Member initialization list(成员初始化列表)；没有此构造函数时调用的是Memberwise initialization(成员逐一初始化)
    // 即class data member 会被依次赋值
    Triangular tri4(tri2);
    tri4.myprint(); // 12, 1, 0

    Triangular tri5 = tri3;
    tri5.myprint(); // 8, 3, 2
}