#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int i){
    if(i == n)
        return 1;
    else if(i > n)
        return 0;
    
    return recursion(n, i+1) + recursion(n, i+2) + recursion(n, i+3);
}

int dynamic(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main(){
    int n = 10;
    cout << recursion(n, 0) << endl;
    cout << dynamic(n) << endl;
    return 0;
}