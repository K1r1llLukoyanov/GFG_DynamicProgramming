#include <bits/stdc++.h>
using namespace std;

int recusion(string str1, string str2, int i, int j){
    if(i >= 0 && j >= 0){
        if(str1[i] == str2[j]){
            return recusion(str1, str2, i-1, j-1);
        }
        else{
            return min(1 + recusion(str1, str2, i, j-1), min( // inserting to str1
                    1 + recusion(str1, str2, i-1, j-1), // replace in str1 or str2
                    1 + recusion(str1, str2, i-1, j))); // remove from str1
        }
    }
    return abs(i-j); // difference between pointers
}

int dynamic(string str1, string str2){
    int n = str1.length(), m = str2.length();
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0){
                dp[i][j] = j;
                continue;
            }
            if(j == 0){
                dp[i][j] = i;
                continue;
            }
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }
    return dp[n][m];
}

int dynamicOptimized(string str1, string str2){
    int n = str1.length(), m = str2.length();
    int dp[2][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0){
                dp[i][j] = j;
                continue;
            }
            if(j == 0){
                dp[i%2][j] = i;
                continue;
            }

            if(str1[i-1] == str2[j-1])
                dp[i%2][j] = dp[(i+1)%2][j-1];
            else
                dp[i%2][j] = 1 + min(min(dp[(i+1)%2][j], dp[i%2][j-1]), dp[(i+1)%2][j-1]);
        }
    }
    return dp[n%2][m];
}

int main(){
    string str1 = "sunday", str2 = "saturday";
    int n = str1.length(), m = str2.length();
    cout << recusion(str1, str2, n-1, m-1) << endl;
    cout << dynamic(str1, str2) << endl;
    cout << dynamicOptimized(str1, str2) << endl;
}