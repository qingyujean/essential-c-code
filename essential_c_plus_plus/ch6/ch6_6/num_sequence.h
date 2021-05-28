#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;

// 由ch5_7修改
// 非类型模板参数 不再需要储存“长度”和“起始位置”这2个数据成员
template <int len, int beg_pos> 
class num_sequence{
public:
    virtual ~num_sequence();

    const char *what_am_i() const; // 返回确切的数列类型

    int elem(int pos) const;
    ostream &print(ostream &os=cout) const;

    static int max_elems() { return _max_elems; }; // 返回最大的元素个数；max_elems与派生类型无关
    // int length() const { return _length; }
    // int beg_pos() const { return _beg_pos; }
private:
protected:
    virtual void gen_elems(int pos) const = 0; // 产生直到pos位置的所有元素；=0表示纯虚函数
    bool check_integrity(int pos, int size) const; // 检查pos位置是否为有效位置；check_integrity与派生类型无关

    num_sequence(vector<int> *pe): _pelems(pe) {} // 构造函数

    static const int _max_elems = 1024;
    // int _length;
    // int _beg_pos;
    vector<int> *_pelems; // int vector的指针，用来指向派生类中的某个static vector
};

template <int len, int beg_pos> 
inline num_sequence<len,beg_pos>::~num_sequence() {} // 空白定义

template <int len, int beg_pos> 
bool num_sequence<len,beg_pos>::check_integrity(int pos, int size) const{
    if(pos<=0 || pos>max_elems()){
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    if(pos>size)
        gen_elems(pos); // 通过虚拟机制调用对应的gen_elems()
    return true;
}

// 非成员函数？
template <int len, int beg_pos> 
ostream & operator<<(ostream &os, const num_sequence<len,beg_pos> &ns){ // 重载output运算符
    return ns.print(os);
}

template <int len, int beg_pos> 
int num_sequence<len,beg_pos>::elem(int pos) const {
    if(!check_integrity(pos, _pelems->size()))
        return 0;
    return (*_pelems)[pos-1];
}

template <int len, int beg_pos> 
ostream & num_sequence<len,beg_pos>::print(ostream &os) const { // 实现时默认参数不能再指定，声明中已经指定
    int elem_pos = beg_pos - 1;
    int end_pos = elem_pos + len;

    if(!check_integrity(end_pos, _pelems->size()))
        return os;
    
    cout << "( " << beg_pos << ", " << len << " ) ";
    while(elem_pos < end_pos){
        os << (*_pelems)[elem_pos++] << ' ';
    }

    return os;
}

template <int len, int beg_pos>
const char * num_sequence<len,beg_pos>::what_am_i() const {
    return typeid(*this).name();
}