#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class americanPut{
public:
    double priceAmericanPut(double S0, double K, double T, double r, int N, double u, double d){
        vector<vector<double>> dp(N+1, vector<double>(N+1,0));
        vector<vector<double>> S(N+1, vector<double>(N+1,0));
        double dt = T / N;
        double R = exp(r*dt);
        double p = (R-d)/(u-d);
        for(int j=0; j<=N; j++){dp[N][j] = max(0., K-S0*pow(u,j)*pow(d,N-j));}
        for(int i=N-1; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[i][j] = max(max(K-S0*pow(u,j)*pow(d,i-j),0.), (1/R)*(p*dp[i+1][j+1] + (1-p)*dp[i+1][j]));
            }
        }
        return dp[0][0];
    }
};

int main(){
    // Parameters
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.06;
    int N = 3;
    double u = 1.1;
    double d = 1 / u;

    americanPut put;
    cout << put.priceAmericanPut(S0, K, T, r, N, u, d) << endl;
    return 0;
}