#include "num_sequence.h"

using namespace std;

// static数据成员只有唯一的一份实体，必须在程序代码文件中提供其清楚定义
const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq); // 存放6个vector
num_sequence::PtrType num_sequence::func_tbl[num_seq] = {
    0,
    &num_sequence::fibonacci,
    &num_sequence::pell,
    &num_sequence::lucas,
    &num_sequence::triangular,
    &num_sequence::sequare,
    &num_sequence::penragonal,
}; // 存放6个member func的地址


int num_sequence::elem(int pos){
    if(!check_integrity(pos))
        return 0;
    if(pos > _elem->size())
        (this->*_pmf)(pos);
    return (*_elem)[pos-1];
}

int main(){
    num_sequence ns;
    const int pos = 8;
    for(int ix=1; ix<num_sequence::num_of_sequence(); ++ix){
        ns.set_sequence(num_sequence::ns_type(ix));
        int elem_val = ns.elem(pos);
        display(cout, ns, pos, elem_val);
    }
}