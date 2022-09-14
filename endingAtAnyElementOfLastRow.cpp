#include <bits/stdc++.h>
using namespace std;

#define N 5
#define M 5

int dynamic(int arr[N][M]){
    int dp[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(i == 0 && j == 0)
                dp[i][j] = arr[i][j];
            else if(j == 0)
                dp[i][j] = dp[i-1][j] + arr[i][j];
            else if(j == i)
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
        }
    }
    int m = dp[N-1][0];
    for(int i = 1; i < M; i++)
        if(m < dp[N-1][i])
            m = dp[N-1][i];
    return m;
}

int main(){
    int arr[N][M] = {{ 4, 2 ,3 ,4 ,1 },
                     { 2 , 9 ,1 ,10 ,5 },
                     {15, 1 ,3 , 0 ,20 },
                     {16 ,92, 41, 44 ,1},
                     {8, 142, 6, 4, 8} };
    cout << dynamic(arr) << endl;
    return 0;
}