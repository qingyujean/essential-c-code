#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* 参考：
line 16 17不加typename会报错：
error: dependent-name 'std::vector<elemType>::const_iterator' is parsed as a non-type, but instantiation yields a type
解决：
https://www.cnblogs.com/dongzhiquan/p/4050997.html
https://blog.csdn.net/pb1995/article/details/49532285/
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
    string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};

    vector<string> svec(sa, sa+4);
    vector<string>::iterator iter1 = svec.begin();
    cout << "string value of elements: " << *iter1 << endl;

    const vector<string> cs_vec(sa, sa+4);
    vector<string>::const_iterator iter2 = cs_vec.begin();
    cout << "string value of elements: " << *iter2 << endl;
    cout << "( " << iter2->size() << " )" << *iter2 << endl;

    display(cs_vec);
}