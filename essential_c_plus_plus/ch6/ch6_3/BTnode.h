using namespace std;

template <typename valType> 
class BTnode; // 前置声明

template <typename valType>
class BTnode{
    friend class BinaryTree<valType>;
public:
    BTnode(const valType &);
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