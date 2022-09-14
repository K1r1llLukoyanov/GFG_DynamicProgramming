#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 5, k = 2; 
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = i*dp[i-1][j-1];
        }
    }

    cout << dp[n][k] << endl;
    
    return 0;
}