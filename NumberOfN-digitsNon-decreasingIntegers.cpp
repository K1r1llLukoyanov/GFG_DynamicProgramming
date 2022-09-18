#include <bits/stdc++.h>
using namespace std;

int dynamic(int n){
    int dp[n+1][10];
    for(int i = 0; i < 10; i++)
        dp[0][i] = 1;
    for(int i = 1; i <= n; i++)
        dp[i][9] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 8; j >= 0; j--)
            dp[i][j] = dp[i-1][j] + dp[i][j+1];
    }
    return dp[n][0];
}

int main(){
    cout << dynamic(3) << endl;
    return 0;
}