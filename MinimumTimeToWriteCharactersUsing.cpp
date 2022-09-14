#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 9;
    int dp[N+1];
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    for(int i = 1; i <= N; i++){
        if(2*i >= N){
            if(dp[N] != -1)
                dp[N] = min(dp[N], dp[i] + 1 + 2*i-N);
            else
                dp[N] = dp[i] + 1 + 2*i-N;
        }
        else{
            if(dp[2*i] != -1)
                dp[2*i] = min(dp[2*i], dp[i] + 1);
            else
                dp[2*i] = dp[i] + 1;
        }
        if(dp[i+1] != -1)
            dp[i+1] = min(dp[i] + 1, dp[i+1]);
        else
            dp[i+1] = dp[i] + 1;
    }
    cout << dp[N] << endl;
    return 0;
}