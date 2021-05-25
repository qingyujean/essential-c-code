#include <iostream>

#include "Triangular.h"

using namespace std;

Triangular::Triangular(){ // default 构造器
    _length = 1;
    _begin_pos = 1;
    _next = 0;
}

Triangular::Triangular(int len){
    _length = len>0 ? len : 1;
    _begin_pos = 1;
    _next = 0;
}

Triangular::Triangular(int len, int bp){
    _length = len>0 ? len : 1;
    _begin_pos = bp>0 ? bp : 1;
    _next = _begin_pos-1;
}

Triangular & Triangular::copy(const Triangular &rhs){
    if(this != &rhs){
        _length = rhs._length;
        _begin_pos = rhs._begin_pos;
        _next = rhs._next;
    }
    return *this;
}

void Triangular::myprint(){
    cout << _length << ' '
         << _begin_pos << ' '
         << _next << endl;
}

int main(){
    Triangular tri1(8);
    Triangular tri2(8, 9);
    tri1.myprint();
    tri2.myprint();

    tri1.copy(tri2);
    tri1.myprint();
}