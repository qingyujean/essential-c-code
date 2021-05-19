#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, int> words;

    string tword;
    while(cin >> tword) // Ctrl+z 表示输入结束
        words[tword]++;

    map<string, int>::iterator it = words.begin();
    for(; it != words.end(); ++it){
        cout << "key: " << it->first 
             << " value: " << it->second << endl;
    }

    // 查询 map 中是否含有某个key
    int count = words["vermeer"];
    if (!count)
        cout << "count= " << count
             << ", not contain: 'vermeer' " << endl;
    // 但是如果这么写，这个key会被自动加入到map中，其值value为默认值0
    /*for(; it != words.end(); ++it){
        cout << "key: " << it->first 
             << " value: " << it->second << endl;
    }*/

    count = 0;
    map<string, int>::iterator it2 = words.find("vermeer"); 
    if(it2 != words.end())
        count = it2->second;
    cout << "count= " << count << endl;

    if(words.count("vermeer"))
        count = words["vermeer"];
    cout << "count= " << count << endl;
}