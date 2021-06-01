using namespace std;

template <typename num_seq>
class NumericSequence{
public:
    NumericSequence(int len=1, int bpos=1): _ns(len, bpos) {}

    void calc_elems(int sz) const { _ns.calc_elems(sz); }
    bool is_elem(int elem) const { return _ns.is_elem(elem); }
private:
    num_seq _ns;
};