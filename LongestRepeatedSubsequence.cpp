#include <bits/stdc++.h>
using namespace std;

int recursion(string a, int i, int j, int n){
    if(i < n && j < n){
        if(a[i] == a[j] && i != j)
            return 1 + recursion(a, i+1, j+1, n);
        else
            return max(recursion(a, i+1, j, n), recursion(a, i, j+1, n));
    }
    return 0;
}

int dynamic(string a){
    int n = a.length();
    int dp[n+1][n+1];
    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == a[j-1] && i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string result = "";
    int i = n, j = n;
    while(dp[i][j] != 0){
        if(dp[i][j] == dp[i-1][j])
            i--;
        else if(dp[i][j] == dp[i][j-1])
            j--;
        else{
            result += a[j-1];
            i--;
            j--;
        }
    }
    reverse(result.begin(), result.end());
    cout << "Longest repeated subsequence: " << result << endl;
    return dp[n][n];
}

int main(){
    string a = "AABEBCDD";
    int n = a.length();
    cout << recursion(a, 0, 0, n) << endl;
    cout << dynamic(a) << endl;
    return 0;
}