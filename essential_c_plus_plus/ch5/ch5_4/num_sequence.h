#include <vector>
#include <iostream>

using namespace std;

class num_sequence{
public:
    virtual ~num_sequence();

    virtual int elem(int pos) const = 0; // 返回pos位置上的元素；=0表示纯虚函数
    virtual const char *what_am_i() const = 0; // 返回确切的数列类型；=0表示纯虚函数
    virtual ostream &print(ostream &os=cout) const = 0; // 将所有元素写入os；=0表示纯虚函数
    static int max_elems() { return _max_elems; }; // 返回最大的元素个数；max_elems与派生类型无关
private:
protected:
    virtual void gen_elems(int pos) const = 0; // 产生直到pos位置的所有元素；=0表示纯虚函数
    virtual bool check_integrity(int pos) const; // 检查pos位置是否为有效位置；check_integrity与派生类型无关

    const static int _max_elems = 1024;
};

inline num_sequence::num_sequence() {} // 空白定义

bool num_sequence::check_integrity(int pos) const{
    if(pos<=0 || pos>_max_elems){
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    return true;
}

ostream & operator<<(ostream &os, const num_sequence &ns){ // 重载output运算符
    return ns.print(os);
}
