#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 函数模板 function template
template <typename elemType>

void display_message(const string &msg, const vector<elemType> &vec){
    cout << msg;
    for(int ix=0; ix<vec.size(); ++ix){
        elemType t = vec[ix];
        cout << t << ' ';
    }
    cout << endl;
}


int main(){
    const string greeting("Hello, welcome to guess the numeric sequence!\n");

    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> ivec(ia, ia+8);
    display_message(greeting, ivec);
    
    string seq_names[6] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonai"
    };
    vector<string> svec(seq_names, seq_names+6);
    display_message(greeting, svec);
}