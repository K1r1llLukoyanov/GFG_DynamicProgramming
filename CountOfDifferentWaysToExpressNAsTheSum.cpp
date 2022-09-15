#include <bits/stdc++.h>
using namespace std;

int recursion(int N){
    if(N == 0)
        return 1;
    else if(N < 0)
        return 0;
    return recursion(N-1) + recursion(N-3) + recursion(N-4);
}

int dynamic(int N){
    int dp[N+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i <= N; i++)
        dp[i] = dp[i-1] + dp[i-3] + dp[i-4];
    return dp[N];
}

int main(){
    int N = 10;
    cout << recursion(N) << endl;
    cout << dynamic(N) << endl;
    return 0;
}