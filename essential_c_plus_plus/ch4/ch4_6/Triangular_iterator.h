using namespace std;

// class Triangular;

class iterator_overflow: std::overflow_error{
public:
    explicit iterator_overflow():std::overflow_error("Triangular_iterator overflow"){}

    virtual ~iterator_overflow() throw() {}
};

class Triangular_iterator{
public:
    Triangular_iterator(int index): _index(index-1){}

    bool operator==(const Triangular_iterator &) const;
    bool operator!=(const Triangular_iterator &) const;
    int operator*() const;
    Triangular_iterator & operator++(); //++ix 前置版
    Triangular_iterator operator++(int); //ix++ 后置版
private:
    void check_integrity() const;
    int _index;
};

// 非inline成员函数应该在程序代码文件中定义
// class定义和inline成员函数通常会放在class同名的头文件中
inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const {
    return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const {
    return !(*this == rhs);
}

/*
// 解决交叉包含问题
// 将此部分定义写到Triangular.h中Triangular类定义的后面，并声明为inline
inline int Triangular_iterator::operator*() const { // 会访问Triangular的私有成员 _elems
    check_integrity();
    return Triangular::_elems[_index];
}

inline void Triangular_iterator::check_integrity() const{ // 会访问Triangular的私有成员 _max_elems和_elems
    if(_index>=Triangular::_max_elems)
        throw iterator_overflow();
    
    if(_index>=Triangular::_elems.size())
        Triangular::gen_elements(_index+1);
}
*/
inline Triangular_iterator & Triangular_iterator::operator++(){//++ix 前置版
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int){//ix++ 后置版
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
} 
