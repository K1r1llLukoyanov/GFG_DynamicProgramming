#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int recursion(int h){
    if(h == 0)
        return 0;
    else if(h == 1)
        return 1;
    else if(h == 2)
        return 3;
    
    return (recursion(h-1)*((2*recursion(h-2))%mod + recursion(h-1))%mod)%mod;
}

int dynamic(int n){
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1]*((2*dp[i-2])%mod + dp[i-1])%mod)%mod;
    }
    return dp[n];
}

int dynamicSpaceOptimized(int h){
    if(h == 1)
        return 1;
    int a = 1;
    int b = 3;
    for(int i = 3; i <= h; i++){
        int t = b;
        b = (b*((2*a) + b)%mod)%mod;
        a = t;
    }
    return b;
}

int main(){
    cout << dynamic(2) << endl; 
    cout << recursion(2) << endl;
    cout << dynamicSpaceOptimized(2) << endl;
    return 0;
}