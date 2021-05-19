#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string usr_name;
    cout << "input your name: ";
    cin >> usr_name;

    int num_tries = 0, num_right = 0;

    /*
    ofstream outfile("./files/seq_data.txt", ios_base::app); //以追加模式打开文件
    if (!outfile)
        cerr << "Oops! Unable to save session data!\n";
    else
    {
        outfile << usr_name << ' '
                << num_tries << ' '
                << num_right << endl;
    }
    */

    ifstream infile("./files/seq_data.txt"); // 读取文件
    if(!infile)
        cerr << "Cannot open the file!\n";
    else
    {
        string name;
        int num_t, num_correct;
        while(infile >> name){
            infile >> num_tries >> num_correct;
            if (name == usr_name){
                cout << "Welcome back, " << usr_name
                     << "\nYour current score is " << num_correct
                     << " out of " << num_tries << "\nGood Luck!\n";
                num_tries = num_t;
                num_right = num_correct; 
            }
        }
    }
    
    

}