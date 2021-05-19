#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

// function object adapter: negator: not1, not2

vector<int> filter_v2_2(const vector<int> &vec, int val, less<int> l_t){
    vector<int> new_vec;
    vector<int>::const_iterator iter = vec.begin();

    // while( (iter = find_if(iter, vec.end(), bind2nd(l_t, val))) != vec.end() ){
    while( (iter = find_if(iter, vec.end(), not1(bind2nd(l_t, val)))) != vec.end() ){ // 对less than的结果取反，就是求解大于等于
        new_vec.push_back(*iter);
        ++iter;
    }
    return new_vec;
}


vector<int> filter_v4_2(const vector<int> &vec, int val, less<int> l_t){ // sub_vec
    vector<int> local_vec(vec); // 副本
    sort(local_vec.begin(), local_vec.end());

    vector<int>::iterator it = find_if(local_vec.begin(), local_vec.end(), not1(bind2nd(l_t, val)) );

    local_vec.erase(it, local_vec.end());
    return local_vec;
}

int main(){
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    cout << "filtering integer vector for values >= 10\n";
    vector<int> ivec2 = filter_v2_2(ivec, 10, less<int>());
    display(ivec2);

    cout << "filtering integer vector for values < 10\n";
    vector<int> ivec3 = filter_v4_2(ivec, 10, less<int>());
    display(ivec3);
}