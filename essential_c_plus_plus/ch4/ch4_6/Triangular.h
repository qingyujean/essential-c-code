#include "Triangular_iterator.h"

#include <vector>
#include <iostream>

using namespace std;

// class Triangular_iterator;

class Triangular{
    friend class Triangular_iterator;
    //friend int Triangular_iterator::operator*() const;
    //friend void Triangular_iterator::check_integrity() const;
public:
    Triangular(); // default 构造器
    Triangular(int len);
    Triangular(int len, int begin_pos);

    static bool is_elem(int val);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display(int length, int beg_pos, ostream &os=cout);

    typedef Triangular_iterator iterator; // 这么做，可以让用户不必知晓iterator class的实际名称

    Triangular_iterator begin() const {
        return Triangular_iterator(_begin_pos);
    }

    Triangular_iterator end() const {
        return Triangular_iterator(_begin_pos+_length);
    }

private:
    int _length; // 元素个数 // data member
    int _begin_pos; // 起始位置
    mutable int _next; // 下一个迭代目标

    static const int _max_elems = 1024;
    static vector<int> _elems; // 静态数据成员
};


// 解决交叉包含问题
// 参考：https://blog.csdn.net/jiangzhiyuan123/article/details/84680113
inline void Triangular_iterator::check_integrity() const{ // 会访问Triangular的私有成员 _max_elems和_elems
    if(_index>=Triangular::_max_elems)
        throw iterator_overflow();
    
    if(_index>=Triangular::_elems.size())
        Triangular::gen_elements(_index+1);
}

inline int Triangular_iterator::operator*() const { // 会访问Triangular的私有成员 _elems
    check_integrity();
    return Triangular::_elems[_index];
}