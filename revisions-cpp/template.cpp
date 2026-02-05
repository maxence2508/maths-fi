#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> T min(T a, T b){
    return (a<b? a:b);
}

template <class T> void print(const vector<T>& V){
    vector<T> it = V.begin();
    for(; it!=V.end(); ++it){
        cout << *it << endl;
    }
}

template <class T> void print2(const vector<T>& V){
    for(auto it = V.begin; it!=V.end(); it++){
        cout << *it << endl;
    }
}

class CompareInt{
private:
    const int* tab;
public:
    CompareInt(const int* t){
        tab = t;
    }
    bool operator()(int i, int j) const{
        return tab[i] < tab[j];
    }
};

int main(){
    int tab_idx[4] = {0,1,2,3};
    const int ord[4] = {20,10,11,1};
    sort(tab_idx, tab_idx+4, CompareInt(ord));
    for(int i=0; i<4; i++){
        cout << tab_idx[i] << endl;
    }
    cout << endl;
    int tab[4] = {7,9,2,8};
    for(int i=0; i<4; i++){
        cout << tab[tab_idx[i]] << endl;
    }
    return 0;
}