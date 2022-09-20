#include <bits/stdc++.h>
using namespace std;

int binCoef(int n, int k){
    int dp[k+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = min(k, i); j >= 1; j--){
            dp[j] += dp[j-1];
        }
    }
    return dp[k];
}

int lobbNumber(int n, int m){
    return (2*m+1)*binCoef(2*n, m+n)/(n+m+1);
}

int main(){
    int n = 5, m = 3;
    cout << lobbNumber(n, m) << endl;
    return 0;
}