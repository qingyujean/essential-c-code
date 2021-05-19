#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


// 函数声明
//int fibon_elem(int pos);
bool fibon_elem(int pos, int &elem);

/*
int fibon_elem(int pos){
    if(pos<=0)
        exit(-1);

    int elem = 1; // 用于存放返回值
    int n_2 = 1, n_1 = 1;
    for(int ix=3; ix<=pos; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return elem;
}
*/

bool fibon_elem(int pos, int &elem){
    if(pos<=0 || pos>2014)
    {
        elem = 0;
        return false;
    }

    elem = 1;
    int n_2 = 1, n_1 = 1;
    for(int ix=3; ix<=pos; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}

bool print_sequence(int pos){
    if (pos<=0 || pos>1024){
        cerr << "invalid position: " << pos
             << " -- cannot handle request!\n";
        return false;
    }
    
    cout << "The Fibonacci Sequence for " << pos
         << " positions: \n\t";
    switch(pos){
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";break;
    }

    int elem;
    int n_2 = 1, n_1 = 1;
    for(int ix=3; ix<=pos; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
        cout << elem << (!(ix%10) ? "\n\t" : " "); // 一行打印10个元素，否则换行
    }
    cout << endl;
    return true;
}


int main(){
    int pos;
    cout << "Please enter a position: ";
    cin >> pos;

    int elem;
    if(fibon_elem(pos, elem))
        cout << "element # " << pos
             << " is " << elem << endl;
    else
        cout << "Sorry. Could not calculate element # "
             << pos << endl;

    print_sequence(pos);

}