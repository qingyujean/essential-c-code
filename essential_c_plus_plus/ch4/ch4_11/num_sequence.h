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
private:
    PtrType _pmf;
    vector<int> *_elem;

    static const int num_seq = 7;
    static PtrType func_tbl[num_seq]; // 存放6个member func的地址
    static vector<vector<int> > seq; // 存放6个vector
};