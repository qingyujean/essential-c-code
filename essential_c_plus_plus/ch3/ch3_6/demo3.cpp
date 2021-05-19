#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// function object adapter: binder adapter: bind1st, bind2nd

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

// vector<int> filter_v2(const vector<int> &vec, int val, less<int> &l_t){
vector<int> filter_v2(const vector<int> &vec, int val, less<int> l_t){
    vector<int> new_vec;
    vector<int>::const_iterator iter = vec.begin();

    while( (iter = find_if(iter, vec.end(), bind2nd(l_t, val))) != vec.end() ){
        new_vec.push_back(*iter);
        ++iter;
    }
    return new_vec;
}



int main(){
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    cout << "filter before: ";
    display(ivec);

    vector<int> ivec2 = filter_v2(ivec, 10, less<int>()); // 默认使用less-than运算符, 升序
    cout << "filter after: ";
    display(ivec2);
}