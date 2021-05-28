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

int main(){
    BinaryTree<string> bt;

    bt.insert("Piglet");
    bt.insert("Eeyore");
    bt.insert("Roo");
    bt.insert("Tigger");
    bt.insert("Chris");
    bt.insert("Pooh");
    bt.insert("Kanga");

    cout << "Preorder traversal: \n";
    bt.preorder();

    bt.remove("Piglet"); // 删除根节点
    cout << "\n\nPreorder traversal after Piglet removal: \n";
    bt.preorder();

    bt.remove("Eeyore"); // 删除其中一个节点
    cout << "\n\nPreorder traversal after Eeyore removal: \n";
    bt.preorder();

    return 0;
}