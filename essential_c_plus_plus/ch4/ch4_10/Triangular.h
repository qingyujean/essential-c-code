#include <vector>
#include <iostream>

using namespace std;

class Triangular{
public:
    Triangular(); // default 构造器
    Triangular(int len);
    Triangular(int len, int begin_pos);

    // 以下是const member func
    int length() const {return _length;}
    void length(int len) {_length=len;}
    int beg_pos() const {return _begin_pos;}
    void beg_pos(int bp) {_begin_pos=bp;}
    void next_reset() const {_next = _begin_pos-1;}

    static bool is_elem(int val);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display(int length, int beg_pos, ostream &os=cout);

private:
    int _length; // 元素个数 // data member
    int _begin_pos; // 起始位置
    mutable int _next; // 下一个迭代目标

    static const int _max_elems = 1024;
    static vector<int> _elems; // 静态数据成员
};