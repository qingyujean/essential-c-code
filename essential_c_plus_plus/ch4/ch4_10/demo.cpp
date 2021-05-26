#include <iostream>
#include <vector>

#include "Triangular.h"

using namespace std;


// 既支持指针，又支持指向容器的iterator ch3_2
template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value){
    for(; first != last; ++first)
        if(*first == value)
            return first;
    return last;
}

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


/*
Triangular::Triangular(int len, int bp){
    _length = len>0 ? len : 1;
    _begin_pos = bp>0 ? bp : 1;
    _next = _begin_pos-1;
}
*/

Triangular::Triangular(int len, int bp): _length(len>0? len : 1), _begin_pos(bp>0 ? bp : 1) {
    _next = _begin_pos-1;
    int elem_cnt = _begin_pos + _length - 1;
    if(_elems.size() < elem_cnt)
        gen_elements(elem_cnt);
}

vector<int> Triangular::_elems; // static数据成员只有唯一的一份实体，必须在程序代码文件中提供其清楚定义
// int Triangular::_initial_size = 8;


// 静态类成员函数 只有在“不访问任何非静态成员”的条件下才能被声明为static，例如下面的这些static member func只访问了静态的_elems
bool Triangular::is_elem(int value){
    if(!_elems.size() || _elems[_elems.size()-1]<value)
        gen_elems_to_value(value);

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}


void Triangular::gen_elements(int length){
    if(length<0 || length>_max_elems){
        cerr << " length is not ok! " << length << endl;
        return;
    }

    if(_elems.size() < length){
        int ix = _elems.size()? _elems.size()+1 : 1;
        for(; ix<=length; ++ix)
            _elems.push_back(ix * (ix+1)/2);
    }
}


void Triangular::gen_elems_to_value(int value){
    int ix = _elems.size();
    if(!ix){
        _elems.push_back(1);
        ix = 1;
    }

    while(_elems[ix-1]<value && ix<_max_elems){
        ++ix;
        _elems.push_back(ix * (ix+1)/2);
    }

    if(ix==_max_elems)
        cerr << "Triangular Sequence: oops: value too large "
             << value << " -- exceeds max size of "
             << _max_elems << endl;
}

void Triangular::display(int length, int beg_pos, ostream &os){ // ostream &os=cout 默认参数在声明里写了就行，在定义时不要写，写了会报错
    if(length<=0 || beg_pos<=0){
        cerr << "invalid parameters -- unable to fulfill request: "
             << length << ", " << beg_pos << endl;
        return;
    }

    int elems = beg_pos+length-1;
    if(_elems.size() < elems)
        gen_elements(elems);   
    
    for(int ix = beg_pos-1; ix < elems; ++ix )
        os << _elems[ix] << ' ';
}


// new add: 
ostream & operator<<(ostream &os, const Triangular &rhs){ // 重载output运算符
    os << "( " << rhs.beg_pos() << ", "
       << rhs.length() << " )";
    
    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

istream & operator>>(istream &is, Triangular &rhs){
    char ch1, ch2;
    int bp, len;

    is >> ch1 >> bp >> ch2 >> len;

    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.next_reset();

    return is;
}


int main(){
    Triangular tri(6, 3);
    cout << tri << '\n';

    Triangular tri2;
    cin >> tri2;

    cout << tri2;
}