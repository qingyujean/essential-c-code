#include <iostream>
#include <vector>

using namespace std;

int * find(const vector<int> &vec, int value){
    for(int ix=0; ix<vec.size(); ++ix)
        if(vec[ix] == value)
            return (int *)&vec[ix]; // const int * 强转 int *
    return 0;
} 

template <typename elemType>
elemType * find(const vector<elemType> &vec, const elemType &value){
    for(int ix=0; ix<vec.size(); ++ix)
        if(vec[ix] == value)
            return &vec[ix];
    return 0;
}


template <typename elemType>
elemType * find11(const elemType *array, int size, const elemType &value){
    if(!array || size<1)
        return 0;
    
    for(int ix=0; ix<size; ++ix)
        if(array[ix] == value)
            return (elemType *)&array[ix];
    return 0;
}

template <typename elemType>
elemType * find12(const elemType *array, int size, const elemType &value){
    if(!array || size<1)
        return 0;
    
    for(int ix=0; ix<size; ++ix,++array)
        if(*array == value)
            return (elemType *)array;
    return 0;
}

template <typename elemType>
elemType * find2(const elemType *first, const elemType *last, const elemType &value){
    if(!first || !last)
        return 0;

    for(; first != last; ++first)
        if(*first == value)
            return (elemType *)first;
    return 0;
}

int main(){
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia+8);

    int *res = find(vec, 3);
    cout << res << ' ' << *res << endl;

    res = find(vec, 13);
    cout << res << ' ' << *res << endl;
    cout << endl;

    double da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};

    double *res2 = find11(da, 6, 2.0);
    cout << res2 << ' ' << *res2 << endl;

    res2 = find12(da, 6, 2.5);
    cout << res2 << ' ' << *res2 << endl;

    res2 = find2(da, da+6, 3.0);
    cout << res2 << ' ' << *res2 << endl;
}