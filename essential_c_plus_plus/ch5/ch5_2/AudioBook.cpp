#include <iostream>

#include "AudioBook.h"

using namespace std;

void print(const LibMat &mat){
    cout << "in global print(): about to print mat.print()\n";
    mat.print();
}

int main(){
    cout << "\n" << "Creating a AudioBook object to print()\n";
    AudioBook ab("Man Without Qualities", "Robert Musil", "Kenneth Meyer");
    print(ab);


    cout << endl;
    AudioBook ab2("Mason and Dixon", "Thomas Pynchon", "Edwin Leonard");
    cout << "My title is: " << ab2.title() << '\n'
         << "My auor is: " << ab2.author() << '\n'
         << "My narrator is: " << ab2.narrator() << endl; 
}