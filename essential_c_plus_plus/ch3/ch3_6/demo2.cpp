#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // function object

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

int main(){
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    cout << "sort before: ";
    display(ivec);

    sort(ivec.begin(), ivec.end()); // 默认使用less-than运算符, 升序
    cout << "sort after (asc order): ";
    display(ivec);

    sort(ivec.begin(), ivec.end(), greater<int>()); // 使用greater-than, 降序
    cout << "sort after (desc order): ";
    display(ivec);
}