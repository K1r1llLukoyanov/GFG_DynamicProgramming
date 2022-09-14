#include <bits/stdc++.h>
using namespace std;

int dynamic(string a, string b){
    int n = a.length(), m = b.length();
    int dp[2][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0){
                dp[i][j] = 0;
                continue;
            }
            else if(j == 0){
                dp[i%2][j] = 0;
                continue;
            }
            if(a[i-1] == b[j-1])
                dp[i%2][j] = 1 + dp[(i+1)%2][j-1];
            else
                dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
        }
    }
    int i = n;
    int j = m;
    string res = "";
    while(i > 0 && j > 0 && dp[i%2][j] != 0){
        if(dp[i%2][j] == dp[(i-1)%2][j])
            i--;
        else if(dp[i%2][j] == dp[i%2][j-1])
            j--;
        else{
            res += a[i-1];
            i--;
            j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << "LCS: " << res << endl;
    return dp[n%2][m];
}

int main(){
    string a = "AGGTAB", b = "GXTXAYB";
    cout << dynamic(a, b) << endl;
    return 0;
}