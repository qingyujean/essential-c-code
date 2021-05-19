#include <string>
#include <iostream>
#include <complex>

using namespace std;

int main(){
    string user_name;
    cout << "input your name: ";
    cin >> user_name;

    int usr_val;
    int num_tries = 0, num_right = 0;

    string sequence_name = "Fibonacci";

    complex<double> purei(0, 7);

    double usr_score = 0.0;

    char usr_more;
    cout << "Try another aequence? Y/N? ";
    cin >> usr_more;

    cout << "\n\t" << user_name;

    bool go_for_it = true;

    const int max_tries = 3;
    const double pi = 3.14159;
}