#include <vector>

using namespace std;

// 函数声明
bool seq_elem(int pos, int &elem);

const vector<int> *fibon_seq(int size);
const vector<int> *lucas_seq(int size);
const vector<int> *pell_seq(int size);
const vector<int> *triang_seq(int size);
const vector<int> *square_seq(int size);
const vector<int> *pent_seq(int size);

// 变量/对象声明
const int seq_cnt = 6;
extern const vector<int> * (*seq_array[])(int); // seq_array是一个执行const对象的指针，它本身并不是const object，所以需要加extern声明