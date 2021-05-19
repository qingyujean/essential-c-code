#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    const int seq_size = 18;
    int pell_seq1[ seq_size ];

    // vector<int> pell_seq2( seq_size );
    pell_seq1[0] = 1;
    pell_seq1[1] = 2;
    for(int ix=2; ix<seq_size; ++ix)
        pell_seq1[ix] = pell_seq1[ix-2]+2*pell_seq1[ix-1];

    cout << "The first " << seq_size
         << " elements of the Pell Series:\n\t";

    for(int ix=0; ix<seq_size; ++ix)
        cout << pell_seq1[ix] << ' ';

    cout << '\n';


    int elem_seq1[seq_size] = {
        1, 2, 3,
        3, 4, 7,
        2, 5, 12,
        3, 6, 10,
        4, 9, 16,
        5, 12, 22
    };

    int elem_vals[seq_size]  = {1, 2, 3, 3, 4, 7, 2, 5, 12, 3, 6, 10, 4, 9, 16, 5, 12, 22};
    vector<int> elem_seq2(elem_vals, elem_vals+seq_size); // elem_vals表示实际内存位置
    cout << "The first " << seq_size
         << " elements of the Pell Series:\n\t";
    
    for(int ix=0; ix<elem_seq2.size();++ix)
        cout << pell_seq1[ix] << ' ';
}