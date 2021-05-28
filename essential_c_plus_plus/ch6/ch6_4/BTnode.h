#include <iostream>

using namespace std;

template <typename elemType> 
class BinaryTree; // 前置声明

template <typename valType>
class BTnode{
    friend class BinaryTree<valType>;
public:
    BTnode(const valType &);

    // new add
    void insert_value(const valType &val);
    void remove_value(const valType &val, BTnode * &prev);
    static void lchild_leaf(BTnode *leaf, BTnode *subtree); // 将左子树搬移至right_child的左子树的左下角
    void preorder(BTnode *pt, ostream &os=cout) const; // 先序遍历
    void display_val(BTnode *pt, ostream &os=cout) const;
private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};

template <typename valType>
inline BTnode<valType>::BTnode(const valType &val): _val(val) { // copy constructor
    _cnt = 1;
    _lchild = _rchild = 0;
}

// +------------------------------------- new add ------------------------------------------+
template <typename valType>
void BTnode<valType>::insert_value(const valType &val){
    if(val == _val){
        _cnt++;
        return;
    }
    if(val < _val){
        if(!_lchild)
            _lchild = new BTnode(val);
        else
            _lchild->insert_value(val);
        
    }else{
        if(!_rchild)
            _rchild = new BTnode(val);
        else
            _rchild->insert_value(val);
    }
}

template <typename valType>
void BTnode<valType>::lchild_leaf(BTnode *leaf, BTnode *subtree){ // 将左子树leaf搬移至right_child(subtree)的左子树的左下角
    while(subtree->_lchild)
        subtree = subtree->_lchild;
    subtree->_lchild = leaf;
}



template <typename valType>
void BTnode<valType>::remove_value(const valType &val, BTnode * &prev){ // prev为指针的引用，不仅可以修改指针指向的对象，还可以修改指针本身
    // prev指向当前子树的“根”
    if(val<_val){
        if(!_lchild)
            return; // 不在此二叉树中
        else
            _lchild->remove_value(val, _lchild);
    }else if(val>_val){
        if(!_rchild)
            return; // 不在此二叉树中
        else
            _rchild->remove_value(val, _rchild);
    }else{
        // 找到需删除的节点
        if(_rchild){
            prev = _rchild;
            if(_lchild) // 如果存在左孩子，则将整个左子树链接到右子树的左下角
                if(!prev->_lchild)
                    prev->_lchild = _lchild;
                else
                    BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
        }else
            prev = _lchild;
        delete this;
    }
}

template <typename valType>
inline void BTnode<valType>::display_val(BTnode *pt, ostream &os) const {
    os << pt->_val;
    if(pt->_cnt > 1)
        os << "( " << pt->_cnt << " )";
    else
        os << " ";
}