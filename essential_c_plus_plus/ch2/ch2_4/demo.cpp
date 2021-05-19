#include <iostream>
#include <vector>

using namespace std;

const vector<int> * fibon_seq(int size){
    const int max_size = 1024;
    static vector<int> elems;

    static vector<int> elems_tmp;

    if(size<=0 || size>max_size)
    {
        cerr << "fibon_seq(): oops: invalid size: "
             << size << " -- can't fullfil request.\n";
        return 0;
    }

    // 如果size <= elems.size() 就不必重新计算
    if(size <= elems.size()){ // 实现有待纠正，没有切片操作？
        elems_tmp.clear();
        for(int ix=0; ix<size; ++ix){
            elems_tmp.push_back(elems[ix]);
        }
        return &elems_tmp;
    } 
    
    

    for(int ix=elems.size(); ix<size; ++ix){
        if(ix==0 || ix==1)
            elems.push_back(1);
        else
            elems.push_back( elems[ix-1]+elems[ix-2]);
    }
    return &elems;
}

void print_vec(const vector<int> &vec){
    for(const auto &c: vec)
        cout << c << " ";
    cout << endl;
}
int main(){
    const vector<int> *res = fibon_seq(24);
    print_vec(*res);

    print_vec(*fibon_seq(8));
    print_vec(*fibon_seq(18));
    print_vec(*fibon_seq(32));
}