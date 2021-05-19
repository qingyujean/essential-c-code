#include <iostream>
#include <vector>

#include "NumSeq.h"

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

const vector<int> * fibon_seq(int size){
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

bool seq_elem(int pos, int &elem, const vector<int> * (*seq_ptr)(int)){
    if(!seq_ptr) // 检查函数指针
        cout << "Internal Error: seq_ptr is set to null!\n";

    const vector<int> *pseq = seq_ptr(pos); // 调用
    if(!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos-1];
    return true;
}


int main(){
    const vector<int> * (*seq_ptr)(int) = 0; // 函数指针初值可设为0，表示不指向任何函数
    
    seq_ptr = fibon_seq;
    
    int elem;
    int pos = 24;
    seq_elem(pos, elem, seq_ptr);
    cout << "element # " << pos
             << " is " << elem << endl;

    pos = 8;
    // seq_elem(pos, elem, seq_ptr);
    seq_elem(pos, elem, &fibon_seq);
    cout << "element # " << pos
             << " is " << elem << endl;

    pos = 18;
    // seq_elem(pos, elem, seq_ptr);
    seq_elem(pos, elem, *fibon_seq);
    cout << "element # " << pos
             << " is " << elem << endl;

    pos = 32;
    // seq_elem(pos, elem, seq_ptr); 
    seq_elem(pos, elem, *****fibon_seq);
    cout << "element # " << pos
             << " is " << elem << endl;

}