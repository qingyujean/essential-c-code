#include <iostream>
#include <fstream>
#include <vector>

#include "NumericSeq.h"

using namespace std;

void display(const vector<int> &vec, ostream &os){ // 使用了头文件声明，并在声明中指定默认参数后，函数定义时就不能再指定默认参数
    for(int ix=0; ix<vec.size(); ++ix)
        os << vec[ix] << ' ';
    os << endl;
}

void swap(int &val1, int &val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubble_sort(vector<int> &vec, ostream *ofil=0){
    for(int ix=0; ix<vec.size(); ++ix){
        for(int jx=ix+1; jx<vec.size(); ++jx){
            if(vec[jx] < vec[ix]){
                if(ofil!=0){
                    (*ofil) << "about to call swap! ix: " << ix
                            << " jx: "<< jx << "\tswapping: "
                            << vec[ix] << " with " << vec[jx] << endl;
                }
                swap(vec[ix], vec[jx]);
            }
        }
    }
}

int main(){
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia+8);

    //bubble_sort(vec); // 等价于调用bubble_sort(vec, 0); 不会产生调试信息
    //display(vec);

    ofstream ofil("./files/data.txt");
    bubble_sort(vec, &ofil); // 会产生调试信息
    display(vec);
    display(vec, ofil);
}