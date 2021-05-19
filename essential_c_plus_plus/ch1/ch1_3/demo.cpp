#include <iostream>
#include <string>

using namespace std;

int main(){
    const int line_size = 8;
    int cnt = 1;

    while (cnt < 10){
        string a_string = "hello world! ";
        cout << a_string << ( cnt%line_size ? ' ': '\n');
        cnt += 1;
    }
    cout << "\n\n";

    int tries = 0;
    cout << "Are you ready for try #" 
         << ++tries << "?\n";
    
    //int tries = 1;
    cout << "Are you ready for try #" 
         << tries++ << "?\n";

    double usr_score = 0.0;
    bool usr_more = true;
    char usr_rsp;
    cout << "Try another aequence? Y/N? ";
    cin >> usr_rsp;
    if (usr_rsp == 'N' || usr_rsp == 'n')
        usr_more = false;
    if (usr_more == false)
        cout << "Your score for this session is "
             << usr_score << " Bye!\n";

    
}