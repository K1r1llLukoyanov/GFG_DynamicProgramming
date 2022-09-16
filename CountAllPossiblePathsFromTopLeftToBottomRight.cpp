#include <bits/stdc++.h>
using namespace std;

int dynamic(int n, int m){
    int dp[2][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0)
                dp[i%2][j] = 1;
            else
                dp[i%2][j] = dp[i%2][j-1] + dp[(i+1)%2][j];
        }
    return dp[(n-1)%2][m-1];
}

int main(){
    cout << dynamic(2, 2) << endl;
    return 0;
}