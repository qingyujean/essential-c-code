#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

template <typename valType>
void BTnode<valType>::preorder(BTnode *pt, ostream &os) const {
    if(pt){
        display_val(pt, os);
        if(pt->_lchild)
            preorder(pt->_lchild, os);
        if(pt->_rchild)
            preorder(pt->_rchild, os);
    }
}

template <typename elemType>
inline ostream & operator<<(ostream &os, const BinaryTree<elemType> &bt) {
    os << "Tree: " << endl;
    bt.print(os);
    return os;
}

int main(){
    BinaryTree<string> bts;

    bts.insert("Piglet");
    bts.insert("Eeyore");
    bts.insert("Roo");
    bts.insert("Tigger");
    bts.insert("Chris");
    bts.insert("Pooh");
    bts.insert("Kanga");

    cout << bts << endl;
}