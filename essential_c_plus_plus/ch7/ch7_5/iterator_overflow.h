#include <iostream>
#include <exception>
#include <sstream> // ostringstream
#include <string>

using namespace std;

class iterator_overflow : public exception{
public:
    iterator_overflow(int index, int max): _index(index), _max(max) {}

    int index() { return _index; }
    int max() { return _max; }

    const char * what() const; // 覆盖exception::what()
    }
private:
    int _index;
    int _max;
};


const char * iterator_overflow::what() const{ 
    ostringstream ex_msg;
    static string msg;


    ex_msg << "Internal error: current index " << _index // 将输出信息写到内存内的ostringstream对象之中，将不同类型的数据 格式化为字符串
           << " exceeds maximum bound: " << _max;
    
    msg = ex_msg.str(); // str() 返回 格式化后的字符串

    return msg.c_str(); // 将string对象转化为const char* 类型
}