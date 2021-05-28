#include <vector>
#include <iostream>

using namespace std;

// 全局作用域内的函数及对象，其地址也是一种常量表达式，也可以被拿来表达模板的参数
template <void (*pf)(int pos, vector<int> &seq)> 
class numeric_sequence{
public:
    numeric_sequence(int len, int beg_pos=1){ // 构造函数
        if(!pf)
            cerr << "func pointer is null!\n";
        _len = len>0? len : 1;
        _beg_pos = beg_pos>0? beg_pos : 1;
        pf(beg_pos+len-1, _elems);
    }

    ostream &print(ostream &os=cout) const;
private:
    int _len;
    int _beg_pos;
    vector<int> _elems;
};

template <void (*pf)(int pos, vector<int> &seq)>
ostream & numeric_sequence<pf>::print(ostream &os) const { // 实现时默认参数不能再指定，声明中已经指定
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _len;
    
    cout << "( " << _beg_pos << ", " << _len << " ) ";
    while(elem_pos < end_pos){
        os << _elems[elem_pos++] << ' ';
    }

    return os;
}