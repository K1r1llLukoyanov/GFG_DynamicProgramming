#include <bits/stdc++.h>
using namespace std;

int dynamic(int n, int k, int x){
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n; i++)
        dp[i] = dp[i-1]*(k-2) + dp[i-2]*(k-1);
    
    return x == 1 ? (k-1)*dp[n-2] : dp[n-1];
}

int main(){
    
    return 0;
}