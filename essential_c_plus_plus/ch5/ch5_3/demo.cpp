#include <iostream>

#include "num_sequence.h"

using namespace std;

// static数据成员只有唯一的一份实体，必须在程序代码文件中提供其清楚定义
const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq); // 存放6个vector
num_sequence::PtrType num_sequence::func_tbl[num_seq] = {
    0,
    &num_sequence::fibonacci,
    &num_sequence::pell,
    &num_sequence::lucas,
    &num_sequence::triangular,
    &num_sequence::sequare,
    &num_sequence::penragonal,
}; // 存放6个member func的地址


int num_sequence::elem(int pos){
    if(!check_integrity(pos))
        return 0;
    if(pos > _elem->size())
        (this->*_pmf)(pos);
    return (*_elem)[pos-1];
}

void num_sequence::set_sequence(ns_type nst){
    switch (nst)
    {
        default:
            cerr << "invalid type: setting to 0\n";
            // break;
        case ns_unset:
            _pmf = 0;
            _elem = 0;
            _isa = ns_unset;
            break;
        case ns_fibonacci:
        case ns_pell:
        case ns_lucas:
        case ns_triangular:
        case ns_square:
        case ns_pentagonal:
            _pmf = func_tbl[nst];
            _elem = &seq[nst];
            _isa = nst;
            break;
    }
}

const char *num_sequence::what_am_i() const{
    static char *names[num_seq] = {
        "notSet",
        "fibonacci", "pell", "lucas", "triangular", "square", "pentagonal"
    };
    return names[_isa];
}

inline void display(ostream &os, const num_sequence &ns, int pos){
    os << "The element at position " << pos << " for the "
       << ns.what_am_i() << " sequence is " << ns.elem(pos) << endl;
}



int main(){
    num_sequence ns;
    const int pos = 8;
    for(int ix=1; ix<num_sequence::num_of_sequence(); ++ix){
        ns.set_sequence(num_sequence::ns_type(ix));
        int elem_val = ns.elem(pos);
        display(cout, ns, pos, elem_val);
    }
}