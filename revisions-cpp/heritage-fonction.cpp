#include <iostream>
#include <cmath>
using namespace std;

class Fonction{
public:
    virtual float operator()(float x) const=0;
    virtual Fonction* derivee() const=0;
    virtual float inverse(float y) const;
    virtual ~Fonction() = default;
};

float Fonction::inverse(float y) const{
    Fonction* df = derivee();
    float eps = 1e-5f;
    float u = 1.0; 
    float v = 2.0;
    while(abs(u-v)>eps){
        float tmp = v;
        v = u + (y-(*this)(u)) / (*df)(u);
        u = tmp;
    }
    delete df;
    return v;
}

class Polynome: public Fonction{
protected:
    float* tab;
    int deg;
public:
    Polynome(){tab=nullptr; deg=0;}
    Polynome(float* tab_, int deg_){tab=tab_; deg=deg_;}
    float operator()(float x) const;
    Fonction* derivee() const;
    virtual ~Polynome(){delete [] tab;}
};

float Polynome::operator()(float x) const{
    float res = 0;
    float pow = 1;
    for(int i=0; i<=deg; i++){
        res += tab[i] * pow;
        pow *= x;
    }
    return res;
}

Fonction* Polynome::derivee() const{
    if (deg == 0) {
        return new Polynome(nullptr, 0);
    }

    float* tab_df = new float[deg];   // taille = deg
    for(int i = 0; i < deg; i++){
        tab_df[i] = (i + 1) * tab[i + 1];
    }
    return new Polynome(tab_df, deg - 1);
}

class Affine: public Polynome{
private:
    float a; 
    float b;
public:
    Affine(float a_, float b_){a=a_; b=b_;}
    float operator()(float x) const{return a*x+b;}
    Fonction* derivee() const;
    float inverse(float y) const;
};

Fonction* Affine::derivee() const{
    return new Affine(0.0f, a);

}

float Affine::inverse(float y) const{
    return (y-b) / a;
}

int main(){
    int deg = 2;
    float* tab = new float[4];
    tab[0] = 1.0; tab[1] = 2.0; tab[2] = 1.0;
    Fonction* pol = new Polynome(tab, deg);
    cout << (*pol)(3) << endl;
    cout << pol->inverse(0.1) << endl;
    Fonction* d_pol = pol->derivee();
    cout << (*d_pol)(1) << endl;
    delete d_pol;
    delete pol;
    return 0;
}