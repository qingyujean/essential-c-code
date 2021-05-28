#include <iostream>

#include "num_sequence.h"

using namespace std;

// 非类型模板参数
template <int length, int beg_pos=1>
class Fibonacci: public num_sequence<length, beg_pos> { // Fibonacci必须为从基类继承而来的每个纯虚函数提供对应的实现
public:
    Fibonacci(): num_sequence<length, beg_pos>(&_elems){}; // 构造函数
private:
protected:
    static vector<int> _elems;

    virtual void gen_elems(int pos) const; // 产生直到pos位置的所有元素；为继承而来的纯虚函数提供实现
};

template <int length, int beg_pos>
void Fibonacci<length,beg_pos>::gen_elems(int pos) const {
    if(pos<=0 || pos>num_sequence<length, beg_pos>::max_elems()) // 参考：https://blog.csdn.net/avagrant158/article/details/7207083
        return;

    if(_elems.empty())
        {
            _elems.push_back(1);
            _elems.push_back(1);
        }
    
    if(_elems.size() <= pos){
        int ix = _elems.size();
        int n_2 = _elems[ix-2];
        int n_1 = _elems[ix-1];

        int elem;
        for(; ix<=pos; ++ix){
            elem = n_2 + n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}


// Jane：放在此处或放在demo.cpp中均可以
template <int length, int beg_pos>
vector<int> Fibonacci<length,beg_pos>::_elems; // static数据成员只有唯一的一份实体，必须在程序代码文件中提供其清楚定义
