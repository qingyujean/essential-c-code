#include <iostream>

#include "../ch5_2/AudioBook.h"

using namespace std;

void print(LibMat object, const LibMat *pointer, const LibMat &ref){
    cout << "in global print(): about to print mat.print()\n";
    object.print(); // 调用LibMat::print()  虚函数被静态解析
    pointer->print(); // 虚函数机制
    ref.print(); // 虚函数机制
}

int main(){
    AudioBook iWish("Her Pride of 10", "Stanley Lippman", "Jeremy Irons");
    print(iWish, &iWish, iWish);
}