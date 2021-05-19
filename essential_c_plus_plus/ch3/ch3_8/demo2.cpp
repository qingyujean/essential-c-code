#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

void my_print(set<int> &iset){
    set<int>::iterator it = iset.begin();
    for(; it != iset.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}   

int main(){
    int ia[10] = {1, 3, 5, 8, 5, 3, 1, 5, 8, 1};
    vector<int> vec(ia, ia+10);

    set<int> iset(vec.begin(), vec.end());
    my_print(iset);

    iset.insert(13);
    my_print(iset);

    int ia2[8] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec2(ia2, ia2+8);
    iset.insert(ivec2.begin(), ivec2.end());
    my_print(iset);
}