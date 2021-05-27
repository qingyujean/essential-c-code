#include <iostream>

#include "../ch5_4/num_sequence.h"

using namespace std;

class Fibonacci: public num_sequence { // Fibonacci必须为从基类继承而来的每个纯虚函数提供对应的实现
public:
    Fibonacci(int len=1, int beg_pos=1): _length(len), _beg_pos(beg_pos) {}

    virtual int elem(int pos) const; // 返回pos位置上的元素；为继承而来的纯虚函数提供实现
    virtual const char *what_am_i() const { return "Fibonacci"; } // 返回确切的数列类型；为继承而来的纯虚函数提供实现
    virtual ostream & print(ostream &os=cout) const; // 将所有元素写入os；为继承而来的纯虚函数提供实现

    int length() const { return _length; } // 访问函数
    int beg_pos() const { return _beg_pos; } // 访问函数
private:
protected:
    int _length;
    int _beg_pos;
    static vector<int> _elems;

    virtual void gen_elems(int pos) const; // 产生直到pos位置的所有元素；为继承而来的纯虚函数提供实现
};

int Fibonacci::elem(int pos) const {
    // if(!check_integrity(pos))
    if(!check_integrity(pos, _elems.size()))
        return 0;
    if(pos>_elems.size())
        Fibonacci::gen_elems(pos); // 这么写是希望函数在编译时就能完成解析，而不是等到运行时才解析，即遮掩虚拟机制
    return _elems[pos-1];
}

void Fibonacci::gen_elems(int pos) const {
    if(_elems.empty())
        {
            _elems.push_back(1);
            _elems.push_back(1);
        }
    
    if(_elems.size() <= pos){
        int ix = _elems.size();
        int n_2 = _elems[ix-2];
        int n_1 = _elems[ix-1];
        for(; ix<=pos; ++ix){
            int elem = n_2 + n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}

ostream & Fibonacci::print(ostream &os) const { // 实现时默认参数不能再指定，声明中已经指定
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;
    if(end_pos>_elems.size())
        Fibonacci::gen_elems(end_pos); // 这么写是希望函数在编译时就能完成解析，而不是等到运行时才解析，即遮掩虚拟机制
    
    cout << "( " << _beg_pos << ", " << _length << " ) ";
    while(elem_pos < end_pos){
        os << _elems[elem_pos++] << ' ';
    }

    return os;
}

/*
// Jane：放在此处或放在demo.cpp中均可以
vector<int> Fibonacci::_elems; // static数据成员只有唯一的一份实体，必须在程序代码文件中提供其清楚定义

// 非成员函数
ostream & operator<<(ostream &os, const num_sequence &ns){ // 重载output运算符
    return ns.print(os);
}
*/