#include <bits/stdc++.h>
using namespace std;

#define N 4

int dynamic(int arr[N][N]){
    int dp[N][N];
    for(int i = 0; i < N; i++)
        dp[0][i] = arr[0][i];

    int m = 0;

    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j == 0){
                if(j != N-1){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + arr[i][j];
                }
                else
                    dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else if(j == N-1){
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + arr[i][j];
                else
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1])) + arr[i][j];
            }
            if(i == N-1)
                if(m < dp[i][j])
                    m = dp[i][j];
        }
    }

    return m;    
}

int main(){
    int arr[N][N] = { {4, 2, 3, 4},
                      {2, 9, 1, 10},
                      {15, 1, 3, 0},
                      {16, 92, 41, 44} };
    cout << dynamic(arr) << endl;
    return 0;
}