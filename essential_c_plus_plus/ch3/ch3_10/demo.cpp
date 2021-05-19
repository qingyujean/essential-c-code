#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string word;
    vector<string> text;

    while(cin >> word)
        text.push_back(word);
    
    sort(text.begin(), text.end());

    for(int ix=0; ix<text.size(); ++ix)
        cout << text[ix] << ' ';
}