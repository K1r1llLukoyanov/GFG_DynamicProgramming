#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    int k = 4;
    int dp[n+1][k+2];
    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
    }
    for(int i = 1; i <= k; i++){
        dp[i][i+1] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}