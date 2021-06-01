#include <iostream>

using namespace std;

template <typename OutStream>
class PrintIt{ // class template
public:
    PrintIt(OutStream &os): _os(os) {}

    template <typename elemType>
    void print(const elemType &elem, char delimiter='\n') { // 这是一个member template func
        _os << elem << delimiter;
    }
private:
    OutStream &_os;
};