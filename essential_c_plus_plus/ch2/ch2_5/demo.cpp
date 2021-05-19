#include <iostream>
#include <vector>

using namespace std;

inline bool is_size_ok(int size){
    const int max_size = 1024;
    if(size<=0 || size>max_size)
    {
        cerr << "Oops: requested size is not supported : "
             << size << " -- can't fullfil request.\n";
        return false;
    }
    return true;
}

inline const vector<int> * fibon_seq(int size){
    static vector<int> elems;

    if(!is_size_ok(size))
        return 0;

    // 如果size <= elems.size() 就不必重新计算
    // 如果size>elems.size()，则需要计算新的
    for(int ix=elems.size(); ix<size; ++ix){
        if(ix==0 || ix==1)
            elems.push_back(1);
        else
            elems.push_back( elems[ix-1]+elems[ix-2]);
    }
    return &elems;
}

inline bool fibon_elem(int pos, int &elem){
    const vector<int> *pseq = fibon_seq(pos);
    if(!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos-1];
    return true;
}

int main(){
    int elem;
    int pos = 24;
    fibon_elem(pos, elem);
    cout << "element # " << pos
             << " is " << elem << endl;

    pos = 8;
    fibon_elem(pos, elem);
    cout << "element # " << pos
             << " is " << elem << endl;

    pos = 18;
    fibon_elem(pos, elem);
    cout << "element # " << pos
             << " is " << elem << endl;

    pos = 32;
    fibon_elem(pos, elem);
    cout << "element # " << pos
             << " is " << elem << endl;
}