#include <iostream>
#include <vector>
#include <algorithm> // find()

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

vector<int> less_than_10(const vector<int> &vec){
    vector<int> new_vec;
    for(int ix=0; ix<vec.size(); ++ix)
        if(vec[ix] < 10)
            new_vec.push_back(vec[ix]);
    return new_vec;
}

// vector<int> less_than(const vector<int> &vec, int less_than_val); // 指定某个上限值作为参数

bool less_than(int v1, int v2){
    return v1 < v2 ? true : false;
}

bool grather_than(int v1, int v2){
    return v1 > v2 ? true : false;
}

vector<int> filter_v1(const vector<int> &vec, int filter_value, bool (*pred)(int, int)); // pred是函数指针，表示传给filter用于比较的某种“关系比较函数”

vector<int> filter_v1(const vector<int> &vec, int filter_value, bool (*pred)(int, int)){
    vector<int> new_vec;
    for(int ix=0; ix<vec.size(); ++ix)
        if(pred(vec[ix], filter_value))
            new_vec.push_back(vec[ix]);
    return new_vec;
}

int count_occurs(const vector<int> &vec, int val){ // 计算vec中等于val的数有多少个
    vector<int>::const_iterator iter = vec.begin();
    int occurs_count = 0; // 计数
    while( (iter = find(iter, vec.end(), val)) != vec.end() ){
        ++occurs_count;
        ++iter;
    }
    return occurs_count;
}

int main(){
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    vector<int> ivec2  = less_than_10(ivec);
    display(ivec2);

    vector<int> less_than_10 = filter_v1(ivec, 10, less_than);
    display(less_than_10);

    int ia3[7] = {6, 10, 8, 4, 10, 7, 10};
    vector<int> ivec3(ia3, ia3+7);
    int cnt = count_occurs(ivec3, 10);
    cout << "==10 elements count: " << cnt << endl;
}