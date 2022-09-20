#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int k){
    if(n == 0 && k == 0)
        return 1;
    if(k == 0)
        return 0;
    
    return recursion(n, k-1) + recursion(n-1, n-k);
}

int dynamic(int n, int k){
    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][i-j];
    }
    
    return dp[n][k];
}

int main(){
    cout << recursion(4, 2) << endl;
    cout << dynamic(4, 2) << endl;
    return 0;
}