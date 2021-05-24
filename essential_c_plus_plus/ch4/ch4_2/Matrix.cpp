#include <iostream>

#include "Matrix.h"

using namespace std;

Matrix::Matrix(const Matrix &rhs): _row(rhs._row), _col(rhs._col){ // copy构造器
    // 对rhs._pmat 所指的数组产生一份完全复本
    int elem_cnt = _row * _col;
    _pmat = new double[elem_cnt];
    for(int ix=0; ix<elem_cnt; ++ix)
        _pmat[ix] = rhs._pmat[ix];
}

int main(){
    
}