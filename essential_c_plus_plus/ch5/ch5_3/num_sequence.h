#include <vector>

using namespace std;

class num_sequence{
public:
    typedef void (num_sequence::*PtrType)(int);

    void fibonacci(int);
    void pell(int);
    void lucas(int);
    void triangular(int);
    void sequare(int);
    void penragonal(int);

    int elem(int pos);

    enum ns_type { ns_unset,
                   ns_fibonacci, ns_pell, ns_lucas, ns_triangular, ns_square, ns_pentagonal };
    static ns_type nstype(int num) {
        return num<=0 || num>=num_seq ? ns_unset : static_cast<ns_type>(num); 
    }// static_cast是个特殊转换记号，可将整数num转换为对应的ns_type枚举项

    void set_sequence(ns_type nst);
    const char *what_am_i() const;
private:
    PtrType _pmf;
    vector<int> *_elem;
    ns_type _isa; // 目前的数列类型

    static const int num_seq = 7;
    static PtrType func_tbl[num_seq]; // 存放6个member func的地址
    static vector<vector<int> > seq; // 存放6个vector
};