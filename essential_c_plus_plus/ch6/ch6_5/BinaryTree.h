#include <iostream>

#include "../ch6_4/BTnode.h"

using namespace std;

template <typename elemType>
ostream & operator<<(ostream &os, const BinaryTree<elemType> &bt); // 前置声明

template <typename elemType>
class BinaryTree {
    friend ostream & operator<<<elemType>(ostream &, const BinaryTree<elemType> &); // new add
    // 友元函数模板问题：参考：https://blog.csdn.net/dongzhongshu/article/details/6200466
public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();
    BinaryTree & operator=(const BinaryTree &);

    bool empty() { return _root==0; }
    void clear()    {
        if(_root){
            clear(_root);
            _root = 0;
        }
    }

    void insert(const elemType &elem);
    void remove(const elemType &elem);
    void remove_root();
    void preorder(ostream &os=cout) const { _root->preorder(_root, os); }

private:
    BTnode<elemType> *_root;

    void copy(BTnode<elemType> *tar, BTnode<elemType> *src); // 将子树src复制到tar
    void clear(BTnode<elemType> *);
    // new add
    ostream & print(ostream &os=cout, void (BinaryTree<elemType>::*traversal)(ostream &) const = &BinaryTree<elemType>::preorder) const;
    // 第2个参数是函数指针 traversal 函数参数为 ostream & 函数限定为const
};

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(): _root(0) {} // default constructor

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree &rhs){ // copy constructor
    copy(_root, rhs._root);
} 

template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree() { clear(); } // destructor

template <typename elemType>
inline BinaryTree<elemType> & BinaryTree<elemType>::operator=(const BinaryTree &rhs){ // copy assignment operator
    if(this!=&rhs){
        clear();
        copy(_root, rhs._root);
    }
    return *this;
} 

template <typename elemType>
inline void BinaryTree<elemType>::insert(const elemType &elem){
    if(!_root)
        _root = new BTnode<elemType>(elem);
    else
        _root->insert_value(elem);
}

template <typename elemType>
inline void BinaryTree<elemType>::remove(const elemType &elem){
    if(_root){
        if(_root->_val == elem)
            remove_root(); // 移除根节点
        else
            _root->remove_value(elem, _root);
    }
}

template <typename elemType>
void BinaryTree<elemType>::remove_root(){
    if(!_root)
        return;
    
    BTnode<elemType> *tmp = _root;
    if(tmp->_rchild){ // 如果right child存在，则right直接取代root
        _root = _root->_rchild;
        if(tmp->_lchild){ // 如果left child存在，则left链接到右子树的左下角
            BTnode<elemType> *lc = tmp->_lchild;
            BTnode<elemType> *newlc = _root->_lchild;
            if(!newlc)
                _root->_lchild = lc;
            else
                BTnode<elemType>::lchild_leaf(lc, newlc);     
        }
    }else{ // 如果right child为空，则left直接取代root
        _root = _root->_lchild;
    }
    delete tmp;   
}

template <typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType> *pt){
    if(pt){
        clear(pt->_lchild);
        clear(pt->_rchild);
        delete pt;
    }
}

// print的实现 参考：http://en.verysource.com/code/6288904_1/btree.cpp.html
// +------------------------------------- new add ------------------------------------------+
template <typename elemType>
ostream & BinaryTree<elemType>::print(ostream &os, 
                                      void (BinaryTree<elemType>::*traversal)(ostream &) const) const {
    (this->*traversal)(os);
    return os;
}
