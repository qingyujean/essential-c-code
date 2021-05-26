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


int Triangular::elem(int pos) const {
    return _elems[pos-1];
}

bool Triangular::next(int &value) const {
    if(_next < _begin_pos + _length -1){
        value = _elems[_next++]; // 编译错误，_next不可修改
        return true;
    }
    return false;
}


/* 参考：
https://www.cnblogs.com/Manual-Linux/p/10996457.html
*/
vector<int> Triangular::_elems;


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

int sum(const Triangular &trian){
    int begin_pos = trian.beg_pos();
    int length = trian.length();
    int sum = 0;
    for(int ix=0; ix<length; ++ix)
        sum += trian.elem(begin_pos+ix);
    return sum;
}

int sum2(const Triangular &trian){
    if(!trian.length())
        return 0;
    
    int val, sum = 0;
    trian.next_reset();
    while(trian.next(val)){
        sum += val;
    }
    return sum;
}

ostream & operator<<(ostream &os, const Triangular &rhs){ // 重载output运算符
    os << "( " << rhs.beg_pos() << ", "
       << rhs.length() << " )";
    
    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

// cout class object 可参考ch4_10
int main(){
    Triangular tri(4);
    cout << tri << " -- sum of elements: "
         << sum2(tri) << endl;

    Triangular tri2(4, 3);
    cout << tri2 << " -- sum of elements: "
         << sum2(tri2) << endl;

    Triangular tri3(4, 8);
    cout << tri3 << " -- sum of elements: "
         << sum2(tri3) << endl;
}