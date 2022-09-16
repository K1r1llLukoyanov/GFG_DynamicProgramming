#include <bits/stdc++.h>
using namespace std;

int recursion(int n){
    if(n < 4)
        return 1;
    if(n == 4)
        return 2;
    
    return recursion(n-1) + recursion(n-4);
}

int dynamic(int n){
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(i >= 4)
            dp[i] = dp[i-1] + dp[i-4];
        else if(i < 4 || i == 1)
            dp[i] = dp[i-1];
        else
            dp[i] = 1;
    }
    return dp[n];
}

int main(){
    cout << dynamic(5) << endl;
    cout << recursion(5) << endl;
    return 0;
}