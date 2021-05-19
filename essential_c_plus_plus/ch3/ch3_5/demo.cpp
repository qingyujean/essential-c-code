#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
extern bool grow_vec(vector<int> &, int);

bool is_elem(vector<int> &vec, int elem){
    vector<int>::iterator it = max_element(vec.begin(), vec.end());
    int max_value = *it;
    if(max_value < elem)
        return grow_vec(vec, elem);
    
    if(max_value == elem)
        return true;

    return binary_search(vec.begin(), vec.end(), elem);
}
*/

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout){
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter)
        os << *iter << ' ';
    os << endl;
}

int main(){
    /*
	int num[]={2,3,1,6,4,5};
	cout<<"最小值是 "<<*min_element(num,num+6)<<endl;
	cout<<"最大值是 "<<*max_element(num,num+6)<<endl;
    */

    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> ivec(ia, ia+asize);

    // int max_value = max_element(ivec.begin(), ivec.end()); // 书上的写法 但是报错了
    vector<int>::iterator it = max_element(ivec.begin(), ivec.end());
    int max_value = *it;
    cout << "max value: " << max_value  << endl;

    // 或者写成：
    int min_value = *min_element(ivec.begin(), ivec.end());
    cout << "min value: " << min_value  << endl;

    // 或者写成：（vector是顺序性容器且递增排列）
    max_value = ivec.empty() ? 0 : ivec[ivec.size()-1];
    cout << "max value: " << max_value  << endl;

    // 拷贝
    vector<int> tmp(ivec.size());
    copy(ivec.begin(), ivec.end(), tmp.begin());
    display(tmp);

    // 排序
    int ia2[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> ivec2(ia2, ia2+8);
    cout << "ivec2: (before sort) ";
    display(ivec2);
    sort(ivec2.begin(), ivec2.end());
    cout << "ivec2: (after sort) ";
    display(ivec2);

    // 二分查找
    bool is_find = binary_search(ivec2.begin(), ivec2.end(), 8);
    cout << "search result: " << is_find << endl;

    is_find = binary_search(ivec2.begin(), ivec2.end(), 56);
    cout << "search result: " << is_find << endl;

}