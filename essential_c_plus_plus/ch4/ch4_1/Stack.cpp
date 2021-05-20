#include <string>
#include <vector>

#include "Stack.h"

using namespace std;

bool Stack::pop(string &elem){ // 非inline成员函数应该在程序代码文件中定义
    if(empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string &elem){ // 非inline成员函数应该在程序代码文件中定义
    if(empty())
        return false;
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem){ // 非inline成员函数应该在程序代码文件中定义
    if(full())
        return false;
    _stack.push_back(elem);
    return true;
}

void fill_stack(Stack &stack, istream &is = cin){
    string str;
    while(is >> str && !stack.full())
        stack.push(str);
    cout << "Read in " << stack.size() << " elements\n";
}

int main(){
    Stack st;

    fill_stack(st);

    if(st.empty()){
        cout << '\n' << "Opps: no strings were read -- bailing out\n";
        return 0;
    }

    string str;
    st.peek(str); // 查看栈顶元素
    cout << "top elem: " << str << endl;

    if(st.size()==1 && str.empty()){
        cout << '\n' << "Opps: no strings were read -- bailing out\n";
        return 0;
    }

    cout << '\n' << "Read in " << st.size() << " strings!\n"
         << "The strings, in reverse order: \n";
    
    while(st.size()){ // 全部出栈，直至栈为空
        if(st.pop(str))
            cout << str << ' ';
    }

    cout << "\n\n" << "There are now " << st.size()
         << " elements in the stack!\n";
    
}