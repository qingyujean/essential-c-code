#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    vector<string> text;

    ifstream in_file("./files/input_file.txt"); // 程序运行前先准备好input_file.txt
    ofstream out_file("./files/output_file.txt");

    if(!in_file || !out_file){
        cerr << "!! unable to open the necessary files.\n";
        return -1;
    }

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    copy(is, eof, back_inserter(text));
    
    sort(text.begin(), text.end());

    ostream_iterator<string> os(out_file, " ");
    copy(text.begin(), text.end(), os);
}