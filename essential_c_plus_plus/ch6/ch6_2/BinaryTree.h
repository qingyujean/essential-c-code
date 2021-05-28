using namespace std;

template <typename elemType> 
class BinaryTree; // 前置声明

template <typename elemType>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();
    BinaryTree & operator=(const BinaryTree &);

    bool empty() { return _root==0; }
    void clear();
private:
    BTnode<elemType> *_root;

    void copy(BTnode<elemType> *tar, BTnode<elemType> *src); // 将子树src复制到tar
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
