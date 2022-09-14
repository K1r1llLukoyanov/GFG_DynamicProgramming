#include <bits/stdc++.h>
using namespace std;

int dynamic(int n){
    int dp[n+1];
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4] + dp[i/5]);
    }
    return dp[n];
}

int main(){
    int n = 60;
    cout << dynamic(n) << endl;
    return 0;
}