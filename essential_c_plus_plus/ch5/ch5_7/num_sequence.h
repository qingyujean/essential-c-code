#include <vector>
#include <iostream>

using namespace std;

class num_sequence{
public:
    virtual ~num_sequence();

    virtual const char *what_am_i() const = 0; // 返回确切的数列类型；=0表示纯虚函数

    // virtual int elem(int pos) const = 0; // 返回pos位置上的元素；=0表示纯虚函数
    int elem(int pos) const;
    // virtual ostream &print(ostream &os=cout) const = 0; // 将所有元素写入os；=0表示纯虚函数
    ostream &print(ostream &os=cout) const;

    static int max_elems() { return _max_elems; }; // 返回最大的元素个数；max_elems与派生类型无关
    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
private:
protected:
    virtual void gen_elems(int pos) const = 0; // 产生直到pos位置的所有元素；=0表示纯虚函数
    bool check_integrity(int pos, int size) const; // 检查pos位置是否为有效位置；check_integrity与派生类型无关

    num_sequence(int len, int bp, vector<int> &re): _length(len), _beg_pos(bp), _relems(re) {}

    const static int _max_elems = 64;
    int _length;
    int _beg_pos;
    vector<int> & _relems; // int vector的引用，用来指向派生类中的某个static vector
};

inline num_sequence::~num_sequence() {} // 空白定义

/*
bool num_sequence::check_integrity(int pos) const{
    if(pos<=0 || pos>_max_elems){
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    return true;
}
*/
bool num_sequence::check_integrity(int pos, int size) const{
    if(pos<=0 || pos>_max_elems){
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    if(pos>size)
        gen_elems(pos); // 通过虚拟机制调用对应的gen_elems()
    return true;
}

// 非成员函数？
ostream & operator<<(ostream &os, const num_sequence &ns){ // 重载output运算符
    return ns.print(os);
}

int num_sequence::elem(int pos) const {
    if(!check_integrity(pos, _relems.size()))
        return 0;
    if(pos>_relems.size())
        gen_elems(pos); // 这么写是希望函数在编译时就能完成解析，而不是等到运行时才解析，即遮掩虚拟机制
    return _relems[pos-1];
}

ostream & num_sequence::print(ostream &os) const { // 实现时默认参数不能再指定，声明中已经指定
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;
    if(end_pos>_relems.size())
        gen_elems(end_pos); // 这么写是希望函数在编译时就能完成解析，而不是等到运行时才解析，即遮掩虚拟机制
    
    cout << "( " << _beg_pos << ", " << _length << " ) ";
    while(elem_pos < end_pos){
        os << _relems[elem_pos++] << ' ';
    }

    return os;
}