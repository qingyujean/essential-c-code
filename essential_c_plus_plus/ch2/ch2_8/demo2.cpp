#include<iostream>
#include <vector>

using namespace std;

// 本篇介绍：函数指针

const vector<int> *fibon_seq(int size);
const vector<int> *lucas_seq(int size);
const vector<int> *pell_seq(int size);
const vector<int> *triang_seq(int size);
const vector<int> *square_seq(int size);
const vector<int> *pent_seq(int size);

//bool fibon_elem(int pos, int &elem){
    // const vector<int> *pseq = fibon_seq(pos);
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
    const vector<int> * (*seq_array[])(int) = { // 函数指针数组，seq_array是数组，数组元素是函数指针
        fibon_seq, lucas_seq, pell_seq, triang_seq, square_seq, pent_seq
    };

    enum ns_type{ // 枚举类型
        ns_fibon, ns_lucas, ns_pell, ns_triang, ns_square, ns_pent
    };

    const vector<int> * (*seq_ptr)(int) = 0; // 函数指针初值可设为0，表示不指向任何函数
    // seq_ptr = pell_seq;
    seq_ptr = seq_array[ns_pell];

}