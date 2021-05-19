#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 既支持指针，又支持指向容器的iterator
template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value){
    for(; first != last; ++first)
        if(*first == value)
            return first;
    return last;
}

int main(){
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21}; // array (指针)

    vector<int> ivec(ia, ia+asize); // vector （iterator）

    list<int> ilist(ia, ia+asize); // list （iterator）

    int *pia = find(ia, ia+asize, 13);
    cout << "array: " << *pia << endl;

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 13);
    cout << "vector: " << *it << endl;

    list<int>::iterator it2;
    it2 = find(ilist.begin(), ilist.end(), 13);
    cout << "list: " << *it2 << endl;
}