#include <iostream>
#include <vector>

#include "numeric_sequence.h"

using namespace std;

void fibonacci(int pos, vector<int> &seq); // 产生pos个元素，放到seq内

void fibonacci(int pos, vector<int> &seq){
    if(pos<=0)
        return;

    if(seq.empty())
        {
            seq.push_back(1);
            seq.push_back(1);
        }
    
    if(seq.size() <= pos){
        int ix = seq.size();
        int n_2 = seq[ix-2];
        int n_1 = seq[ix-1];

        int elem;
        for(; ix<=pos; ++ix){
            elem = n_2 + n_1;
            seq.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

template <void (*pf)(int pos, vector<int> &seq)> 
ostream & operator<<(ostream &os, const numeric_sequence<pf> &ns){ // 重载output运算符
    return ns.print(os);
}

int main(){
    /*
    vector<int> elems;
    fibonacci(8, elems);

    display(elems);
    */
    numeric_sequence<fibonacci> ns_fib(12); // len=12, beg_pos=1
    cout << "ns_fib: " << ns_fib << endl;

    numeric_sequence<fibonacci> ns_fib2(18, 8); // len=18, beg_pos=8
    cout << "ns_fib2: " << ns_fib2 << endl;
}