#include <iostream>

#include "num_sequence.h"

using namespace std;

class Fibonacci: public num_sequence { // Fibonacci必须为从基类继承而来的每个纯虚函数提供对应的实现
public:
    Fibonacci(int len=1, int beg_pos=1);

    virtual const char *what_am_i() const { return "Fibonacci"; } // 返回确切的数列类型；为继承而来的纯虚函数提供实现

    // Fibonacci & operator=(const Fibonacci &);
private:
protected:
    static vector<int> _elems;

    virtual void gen_elems(int pos) const; // 产生直到pos位置的所有元素；为继承而来的纯虚函数提供实现
};

// 构造函数
inline Fibonacci::Fibonacci(int len, int beg_pos): num_sequence(len, beg_pos, _elems) {}
/*
// copy构造器
Fibonacci::Fibonacci(const Fibonacci &rhs): num_sequence(rhs) {}
// copy 赋值运算符
Fibonacci & Fibonacci::operator=(const Fibonacci &rhs) {
    if(this != &rhs)
        num_sequence::operator=(rhs);
    return *this;
}
*/
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


// Jane：放在此处或放在demo.cpp中均可以
vector<int> Fibonacci::_elems; // static数据成员只有唯一的一份实体，必须在程序代码文件中提供其清楚定义
