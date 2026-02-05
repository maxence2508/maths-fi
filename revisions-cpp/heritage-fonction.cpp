#include <iostream>
#include <cmath>
using namespace std;

class Fonction{
public:
    virtual float operator()(float x) const=0;
    virtual Fonction* derivee() const=0;
    virtual float inverse(float y) const;
};

float Fonction::inverse(float y) const{
    Fonction* df = derivee();
    float eps = 1e-5f;
    float u = 1; 
    float v = u + (y-(*this)(u)) / (*df)(u);
    while(abs(u-v)>eps){
        float tmp = v;
        v = u + (y-(*this)(u)) / (*df)(u);
        u = tmp;
    }
    return v;
}

class Polynome: public Fonction{
protected:
    int* tab;
    int deg;
public:
    float operator()(float x) const{
        float res = 0;
        float pow = 1;
        for(int i=0; i<deg; i++){
            res += tab[i] * pow;
            pow *= x;
        }
    return res;
    }
};

float Polynome::operator()(float x) const{
    float res = 0;
    float pow = 1;
    for(int i=0; i<deg; i++){
        res += tab[i] * pow;
        pow *= x;
    }
    return res;
}

class Affine: public Polynome{
private:
    float a; 
    float b;
public:
    float operator()(float x) const{return a*x+b;}
};

int main(){
    return 0;
}