#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Please enter your first name: ";
    //printf("What is your name?\n");
    string user_name;
    cin >> user_name;
    cout << '\n';
    cout << "Hello, ";
    cout << user_name;
    cout << " ... and goodbye!\n";

    cout << "3 + 4 = ";
    cout << 3 + 4;
    cout << '\n';

    cout << '\n'
         << "Hello, "
         << user_name
         << " ... and goodbye!\n";
    
    return 0;
}
