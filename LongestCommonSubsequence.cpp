#include <bits/stdc++.h>
using namespace std;

int recursion(string a, string b, int i, int n, int j, int m){
    if(i < n && j < m){
        if(a[i] == b[j]){
            return 1 + recursion(a, b, i+1, n, j+1, m);
        }
        else
            return max(recursion(a, b, i+1, n, j, m), recursion(a, b, i, n, j+1, m));
    }
    else
        return 0;
}

int dynamic(string a, string b){
    int n = a.length(), m = b.length();
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = n;
    int j = m;
    string result = "";
    while(dp[i][j] != 0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else{
            result += a[i-1];
            i--;
            j--;
        }
    }
    reverse(result.begin(), result.end());
    cout << "Longest Common Subsequence: " << result << endl;
    return dp[n][m];
}


int main(){
    string a = "ABCDGH", b = "AEDFHR";
    int n = a.length(), m = b.length();
    cout << recursion(a, b, 0, n, 0, m) << endl;
    cout << dynamic(a, b) << endl;
    return 0;
}