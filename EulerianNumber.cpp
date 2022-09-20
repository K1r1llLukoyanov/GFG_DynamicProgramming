#include <bits/stdc++.h>
using namespace std;

int eulerian(int n, int m){
    if(m >= n || n == 0)
        return 0;
    if(m == 0)
        return 1;
    
    return (n-m)*eulerian(n-1, m-1) + (m+1)*eulerian(n-1, m);
}

int dynamic(int n, int m){
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i > j){
                if(j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (i-j)*dp[i-1][j-1] + (j+1)*dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}


int main(){
    int n = 3, m = 1;
    cout << eulerian(n, m) << endl;
    cout << dynamic(n, m) << endl;
    return 0;
}