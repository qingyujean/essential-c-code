
using namespace std;

class Matrix{
public:
    Matrix(int row, int col): _row(row), _col(col){
        _pmat = new double[row*col];
    }

    ~Matrix(){
        delete []_pmat;
    }
private:
    int _row, _col;
    double *_pmat;
};