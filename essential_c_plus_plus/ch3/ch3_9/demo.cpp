#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <list>

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter_v3(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred){
    while( (first = find_if(first, last, bind2nd(pred, val))) != last ){
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
}

int main(){
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    
    int ia2[elem_size];
    
    cout << "filtering integer array for values less than 10\n";
    filter_v3(ia, ia+elem_size, ia2, 10, less<int>()); // inserter adapter不能用在array上

    
    vector<int> ivec(ia, ia+elem_size);
    // vector<int> ivec2(elem_size);
    vector<int> ivec2; // 未设定ivec2的大小，调用filter()时如果不使用inserter adapter，赋值操作会产生运行时错误

    cout << "filtering integer vector for values greater than 10\n";
    // filter_v3(ivec.begin(), ivec.end(), ivec2.begin(), 10, greater<int>());
    filter_v3(ivec.begin(), ivec.end(), back_inserter(ivec2), 10, greater<int>());

    // front_inserter 会将ivec中的元素倒着copy到result_lst中
    list<int> result_lst;
    unique_copy(ivec.begin(), ivec.end(), front_inserter(result_lst));

    display(ivec);
    
    list<int>::iterator iter = result_lst.begin();
    for(; iter != result_lst.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
}