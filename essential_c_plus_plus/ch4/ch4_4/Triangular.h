#include <vector>

using namespace std;

class Triangular{
public:
    Triangular(); // default 构造器
    Triangular(int len);
    Triangular(int len, int begin_pos);
    
    Triangular &copy(const Triangular &rhs); // copy func
    void myprint();
private:
    int _length; // 元素个数 // data member
    int _begin_pos; // 起始位置
    mutable int _next; // 下一个迭代目标
};