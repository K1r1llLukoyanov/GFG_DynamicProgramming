#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j){
    if(i == 0 || j == 0)
        return 1;
    return recursion(i-1, j) + recursion(i, j-1);
}

int dynamic(int i, int j){
    int dp[i+1][j+1];
    for(int z = 0; z <= i; z++)
        dp[z][0] = 1;
    for(int z = 0; z <= j; z++)
        dp[0][z] = 1;
    
    for(int k = 1; k <= i; k++)
        for(int z = 1; z <= j; z++)
            dp[k][z] = dp[k-1][z] + dp[k][z-1];
    
    return dp[i][j];
}

int dynamicSpaceOptimized(int n, int m){
    int dp[2][m+1];
    for(int i = 0; i <= m; i++)
        dp[0][i] = 1;
    dp[1][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i%2][j] = dp[(i+1)%2][j] + dp[i%2][j-1];
    
    return dp[n%2][m];
}

int binomialCoeff(int n, int m){
    int C[m+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = min(i, m); j > 0; j--)
            C[j] = C[j-1] + C[j];

    return C[m];
}

int main(){
    cout << recursion(3, 6) << endl;
    cout << dynamic(3, 6) << endl;
    cout << dynamicSpaceOptimized(3, 6) << endl;
    return 0;
}