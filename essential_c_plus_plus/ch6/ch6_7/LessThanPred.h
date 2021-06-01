#include <functional> // less

using namespace std;

template <typename elemType, typename Comp=less<elemType>>
class LessThanPred{
public:
    LessThanPred(const elemType &val): _val(val){}

    elemType val() const { return _val; } // 读取
    void val(const elemType &newval) { _val=newval; } // 写入

    bool operator()(const elemType &val) const; // function call 运算符
private:
    elemType _val;
};

template <typename elemType, typename Comp>
inline bool LessThanPred<elemType,Comp>::operator()(const elemType &val) const {
    return Comp(val, _val);
}