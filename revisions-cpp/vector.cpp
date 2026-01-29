#include <iostream>
#include <cassert>
using namespace std;

class Vector{
private:
    int n;
    double* tab;
public:
    // Constructor
    Vector(int n_coord);
    // Copy constructor
    Vector(const Vector& v); // to do Vector v2 = v1;
    // Destructor
    ~Vector();
    // operator=
    void operator=(const Vector& v); // to do A = B;
    double operator()(int i) const; // const because the object is not modified by the function
    double& operator()(int i);
    double operator*(const Vector& v) const;
};

Vector::Vector(int n_coord){
    n = n_coord;
    tab = new double[n];
    for(int i=0; i<n; i++){
        tab[i] = 0.;
    }
}

Vector::Vector(const Vector& v){
    n = v.n;
    tab = new double[n];
    for(int i=0; i<n; i++){
        tab[i] = v.tab[i];
    }
}

Vector::~Vector(){
    delete [] tab;
}

void Vector::operator=(const Vector& v){
    delete [] tab;
    n = v.n;
    tab = new double[n];
    for(int i=0; i<n; i++){
        tab[i] = v.tab[i];
    }
}

double Vector::operator()(int i) const{
    assert(0<=i && i<n);
    return tab[i];
}

double& Vector::operator()(int i){
    assert(0<=i && i<n);
    return tab[i];
}

double Vector::operator*(const Vector& v) const{
    assert(n==v.n);
    double res = 0;
    for(int i=0; i<n; i++){
        res += tab[i]*v.tab[i];
    }
    return res;
}

int main(){
    int n = 2;
    Vector v1(n);
    Vector v2(n);
    v1(0) = 4; v1(1) = 1;
    v2(0) = 1; v2(1) = 8;
    cout << v1*v2 << endl;
    Vector v3 = v2;
    return 0;
}