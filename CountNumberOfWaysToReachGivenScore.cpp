#include <bits/stdc++.h>
using namespace std;

int dynamic(int n){
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        dp[i] = 0;
    for(int i = 3; i <= n; i++)
        dp[i] += dp[i-3];
    for(int i = 5; i <= n; i++)
        dp[i] += dp[i-5];
    for(int i = 10; i <= n; i++)
        dp[i] += dp[i-10];
    return dp[n];
}

int main(){
    int n = 13;
    cout << dynamic(n) << endl;
    return 0;
}