#include <string>

using namespace std;

class Triangular{
public:
    Triangular(); // default 构造器
    Triangular(int len);
    Triangular(int len, int begin_pos);
    // Triangular(const Triangular &rhs);

    void myprint();
private:
    string _name; // member class object

    int _length; // 元素个数 // data member
    int _begin_pos; // 起始位置
    int _next; // 下一个迭代目标
};


/*
Triangular t; // 自动调用default 构造器
Triangular t2(10, 3); // 调用含有2个参数的构造器
Triangular t3 = 8; // 调用含有1个参数的构造器
Triangular t5(); // 此行将t5定义为一个函数，其参数列表是空的，返回的是Triangular object, 
*/