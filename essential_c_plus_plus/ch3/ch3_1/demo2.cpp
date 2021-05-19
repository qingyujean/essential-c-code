#include <iostream>
#include <vector>

using namespace std;

template <typename elemType>
inline elemType * begin(vector<elemType> &vec){ // 参数加const会报错（书上加了const修饰）
    return vec.empty() ? 0: &vec[0];
}


template <typename elemType>
inline elemType * end(vector<elemType> &vec){
    // return vec.empty() ? 0: &vec.end(); // 注意：end指向末尾元素的下一个元素
    return vec.empty() ? 0: &vec[vec.size()];
}

template <typename elemType>
elemType * find2(const elemType *first, const elemType *last, const elemType &value){
    if(!first || !last)
        return 0;

    for(; first != last; ++first)
        if(*first == value)
            return (elemType *)first;
    return 0;
}

int main(){
    string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};
    vector<string> svec(sa, sa+4);
    string *res = find2(&svec[0], &svec[svec.size()], svec[2]);
    cout << res << ' ' << *res << endl;

    string *sfirst = begin(svec);
    cout << *sfirst << endl;
    string *slast = end(svec);
    cout << *(slast-1) << endl;
    res = find2(begin(svec), end(svec), svec[2]);
    cout << res << ' ' << *res << endl;
}