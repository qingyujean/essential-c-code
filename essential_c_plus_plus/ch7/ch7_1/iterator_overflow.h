#include <iostream>

using namespace std;

class iterator_overflow{
public:
    iterator_overflow(int index, int max): _index(index), _max(max) {}

    int index() { return _index; }
    int max() { return _max; }

    void what_happened(ostream &os=cerr){
        os << "Internal error: current index " << _index 
           << " exceeds maximum bound: " << _max;
    }
private:
    int _index;
    int _max;
};


/*
inline void Triangular_iterator::check_integrity() const{ // 会访问Triangular的私有成员 _max_elems和_elems
    if(_index>=Triangular::_max_elems)
        // throw iterator_overflow(_index, Triangular::_max_elems);
        iterator_overflow ex(_index, Triangular::_max_elems);
        throw ex;
    
    if(_index>=Triangular::_elems.size())
        Triangular::gen_elements(_index+1);
}
*/