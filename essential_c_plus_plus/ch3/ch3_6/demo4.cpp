#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

// function template

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter_v3(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred){
    while( (first = find_if(first, last, bind2nd(pred, val))) != last ){
        cout << "found value: " << *first << endl;
        *at++ = *first++;
        /*
        *at = *first;
        ++at;
        ++first;
        */
    }
    return at;
}


// 另一种解法：先对vector（副本）排序，再以find_if()找出第一个大于指定值的元素位置，然后删除该位置之后的所有元素
vector<int> filter_v4(const vector<int> &vec, int val){ // sub_vec
    vector<int> local_vec(vec); // 副本
    sort(local_vec.begin(), local_vec.end());

    vector<int>::iterator it = find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val) );

    local_vec.erase(it, local_vec.end());
    return local_vec;
}



int main(){
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    
    int ia2[elem_size];
    
    cout << "filtering integer array for values less than 10\n";
    filter_v3(ia, ia+elem_size, ia2, 10, less<int>());

    
    vector<int> ivec(ia, ia+elem_size);
    vector<int> ivec2(elem_size);

    cout << "filtering integer vector for values greater than 10\n";
    filter_v3(ivec.begin(), ivec.end(), ivec2.begin(), 10, greater<int>());

    vector<int> ivec3 = filter_v4(ivec, 10);
    display(ivec3);
    
}