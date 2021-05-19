#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<int> &vec){ // 引用
    for(int ix=0; ix<vec.size(); ++ix)
        cout << vec[ix] << ' ';
    cout << endl;
}

void display2(const vector<int> *vec){ // 指针
    if(!vec)
        cout << "display(): the vector pointer is 0\n";

    for(int ix=0; ix<vec->size(); ++ix)
        cout << (*vec)[ix] << ' ';
    cout << endl;
}

void swap(int &val1, int &val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

// 最小的往前上浮
void bubble_sort(vector<int> &vec){
    for (int ix=0; ix<vec.size(); ++ix){ // n-1趟
        for (int jx=ix+1; jx<vec.size(); ++jx){
            if(vec[jx] < vec[ix])
                swap(vec[ix], vec[jx]); // 交换
        }
    }
}

int main(){
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia+8);

    cout << "vector before sort: ";
    display(vec);
    display2(&vec);

    bubble_sort(vec);
    
    cout << "vector after  sort: ";
    display(vec);
    display2(&vec);
}