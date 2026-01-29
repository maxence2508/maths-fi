#include <iostream>
#include <cassert>
using namespace std;

class Matrix{
private:
    int n, m;
    double* tab;
public:
    Matrix(int nlig, int ncol){
        m = nlig;
        n = ncol;
        tab = new double[nlig*ncol];
    }
    Matrix(int nligcol){
        m = nligcol;
        n = nligcol;
        tab = new double[nligcol*nligcol];
    }
    double operator()(int i, int j) const;
    double& operator()(int i, int j);
    void operator=(const Matrix& A);
    ~Matrix();
    Matrix(const Matrix& A);
};

double Matrix::operator()(int i, int j) const{
        assert(0<=i && i<m && 0<=j && j<n);
        return tab[i*n+j];
}

double& Matrix::operator()(int i, int j){
    assert(0<=i && i<m && 0<=j && j<n);
    return tab[i*n+j];
}

void Matrix::operator=(const Matrix& A){
    m = A.m;
    n = A.n;
    delete [] tab;
    tab = new double[n*m];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            tab[i*n+j] = A.tab[i*n+j];
        }
    }
}

Matrix::~Matrix(){
    delete [] tab;
}

Matrix::Matrix(const Matrix& A){
    m = A.m;
    n = A.n;
    tab = new double[m*n];
    for(int i=0; i<m*n; i++){
        tab[i] = A.tab[i];
    }
}

int main(){
    int m = 5;
    int n = 10;
    Matrix A(m, n);
    A(2, 2) = 24;
    cout << A(2,2) << endl;
    Matrix B(A);
    cout << B(2,2) << endl;
    A(2,2) = 30;
    cout << B(2,2) << endl;
    return 0;
}