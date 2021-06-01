using namespace std;

template <typename elemType>
class LessThan{
public:
    LessThan(const elemType &val): _val(val){}

    elemType val() const { return _val; } // 读取
    void val(const elemType &newval) { _val=newval; } // 写入

    bool operator()(const elemType &val) const; // function call 运算符
private:
    elemType _val;
};

template <typename elemType>
inline bool LessThan<elemType>::operator()(const elemType &val) const {
    return val < _val;
}