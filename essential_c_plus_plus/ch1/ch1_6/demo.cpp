#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    int ival = 1024;
    int *pi = &ival;
    cout << *pi << '\n'; // *pi 读取指针pi所指对象ival的值
    cout << pi; // 读取指针pi的值，是ival的内存地址

    vector<int> fibonacci, lucas, pell, triangular, square, pentagonal;
    vector<int> *pv = 0;
    
    const int seq_cnt = 6;
    vector<int> *seq_addrs[seq_cnt] = {&fibonacci, &lucas, &pell, &triangular, &square, &pentagonal};//seq_addrs是个array，其元素类型是vector<int> *

    vector<int> *current_vec = 0;
    for(int ix=0; ix<seq_cnt; ++ix){
        //current_vec = seq_addrs[ix];
        srand(seq_cnt); // 初始化随机数发生器, srand()用来设置rand()产生随机数时的随机数种子
        int seq_index = rand() % seq_cnt; // rand()返回一随机数值的范围在0至RAND_MAX 间
        current_vec = seq_addrs[seq_index];
    }
}