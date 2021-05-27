#include <iostream>

#include "LibMat.h"

using namespace std;

void print(const LibMat &mat){
    cout << "in global print(): about to print mat.print()\n";
    mat.print();
}

int main(){
    cout << "\n" << "Creating a LibMat object to print()\n";
    LibMat libmat;
    print(libmat);
}