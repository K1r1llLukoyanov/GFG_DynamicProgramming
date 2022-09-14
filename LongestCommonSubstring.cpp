#include <bits/stdc++.h>
using namespace std;

int dynamic(string str1, string str2){
    int n = str1.length(), m = str2.length();
    int dp[n+1][m+1];
    int r = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                r = max(r, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return r;
}

// Space optimized
int dynamicOP(string str1, string str2){
    int n = str1.length(), m = str2.length();
    int dp[2][m+1];
    int r = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i%2][j] = 0;
            else if(str1[i-1] == str2[j-1]){
                dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
                r = max(r, dp[i%2][j]);
            }
            else
                dp[i%2][j] = 0;
        }
    }
    return r;
}

int main(){
    string str1 = "cut", str2 = "cat";
    cout << dynamic(str1, str2) << endl;
    cout << dynamicOP(str1, str2) << endl;
    return 0;
}