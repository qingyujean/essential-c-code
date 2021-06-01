#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> * init_text_vector(ifstream &infile){
    vector<string> *ptext = 0;
    try{
        ptext = new vector<string>;

    }catch(bad_alloc){
        cerr << "ouch. heap memory exhausted!\n";
    }
    return ptext;
}

int main(){
    
}