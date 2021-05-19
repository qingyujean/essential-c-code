#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(){
    map<string, int> words;
    set<string> stop_words {"the", "of", "it"};

    string tword;
    while(cin >> tword){ // Ctrl+z 表示输入结束
        if(stop_words.count(tword)) // tword在stop_words中，则跳过
            continue;
        words[tword]++;
    }

    map<string, int>::iterator it = words.begin();
    for(; it != words.end(); ++it){
        cout << "key: " << it->first 
             << " value: " << it->second << endl;
    }

}