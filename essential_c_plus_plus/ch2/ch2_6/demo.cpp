#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 重载
void display_message(char ch);
void display_message(const string &);
void display_message(const string &, int);
void display_message(const string &, int, int);

void display_message(char ch){
    cout << ch << endl;
}

void display_message(const string &msg){
    cout << msg << endl;
}

void display_message(const string &msg, int elem1){
    cout << msg 
         << "the first number is : " << elem1 
         << endl;
}

void display_message(const string &msg, int elem1, int elem2){
    cout << msg 
         << "the first number is : " << elem1 
         << " and the second number is : " << elem2
         << endl;
}

bool is_size_ok(int size){
    const int max_size = 1024;
    const string msg("Requested size is not supported");

    if(size<=0 || size>max_size)
    {
        display_message(msg, size);
        return false;
    }
    return true;
}

int main(){
    display_message('\n');

    const string greeting("Hello, welcome to guess the numeric sequence!\n");
    display_message(greeting);

    const string msg("Requested size is not supported\n");
    display_message(msg);

    const string seq("The two elements of the sequence are ");
    display_message(seq, 1, 2);


}