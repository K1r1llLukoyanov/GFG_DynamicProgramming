#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int m){
    if(n < m)
        return 1;
    return recursion(n-m, m) + recursion(n-1, m);
}

int dynamic(int n, int m){
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(i > m)
            dp[i] = dp[i-m] + dp[i-1];
        else if(i < m || i == 1)
            dp[i] = 1;
        else
            dp[i] = 2; 
    }
    return dp[n];
}

int main(){
    cout << recursion(12, 4) << endl;
    cout << dynamic(12, 4) << endl;
    return 0;
}