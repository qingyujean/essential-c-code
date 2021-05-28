using namespace std;

template <typename valType> 
class BTnode; // 前置声明

template <typename valType>
class BTnode{
    friend class BinaryTree<valType>;
public:
private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};