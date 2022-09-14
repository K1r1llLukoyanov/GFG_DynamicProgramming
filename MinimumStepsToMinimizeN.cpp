#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
    int dp[n+1];
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        int m = dp[i-1];
        if(i%2 == 0)
            m = min(m, dp[i/2]);
        if(i%3 == 0)
            m = min(m, dp[i/3]);
        dp[i] = m + 1;
    }
    cout << dp[n] << endl;
    return 0;
}