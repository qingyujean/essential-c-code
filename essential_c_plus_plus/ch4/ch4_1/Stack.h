#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack{
public:
    bool push(const string &); // 成员函数都必须在class主体内声明
    bool pop(string &elem);
    bool peek(string &elem);

    bool empty();
    bool full();

    int size(){ // 在class主体内定义，会被自动视为inline函数
        return _stack.size();
    }
private:
    vector<string> _stack;
};

inline bool Stack::empty(){ // class定义和inline成员函数通常会放在class同名的头文件中
    return _stack.empty();
}

inline bool Stack::full(){ // class定义和inline成员函数通常会放在class同名的头文件中
    return _stack.size() == _stack.max_size();
}