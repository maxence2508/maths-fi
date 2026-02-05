#include <iostream>
using namespace std;

class Forme{};

class Ellipse: public Forme{
    float centre[2];
    float extremite[2];
    float axe; // longueur petit axe
public:
    void Transforme(float dx, float dy, float angle);
};

class Quadrilatere: public Forme{
protected:
    float points[4];
public:
    void Transforme(float dx, float dy, float angle);
};

void Ellipse::Transforme(float dx, float dy, float angle){}
void Quadrilatere::Transforme(float dx, float dy, float dz){}


int main(){
    return 0;
}