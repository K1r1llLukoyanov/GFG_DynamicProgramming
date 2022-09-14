#include <bits/stdc++.h>
using namespace std;

int recursion(int m, int n){
    if(m == 0)
        return 0;
    if(n == 1)
        return m;
    return recursion(m/2, n-1) + recursion(m-1, n);
}

int dynamic(int m, int n){
    int dp[m+1][n+1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0){
                dp[i][j] = 0;
                continue;
            }
            if(j == 0){
                dp[i][j] = 0;
                continue;
            }
            else if(j == 1){
                dp[i][j] = i;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i/2][j-1];
        }
    }
    return dp[m][n];
}

int main(){
    cout << dynamic(10, 4) << endl;
    return 0;
}