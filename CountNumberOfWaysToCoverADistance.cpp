#include <bits/stdc++.h>
using namespace std;

int dynamic(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}

int dynamicSpaceOptimized(int n){
    int ways[3];
    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;
    for(int i = 3; i <= n; i++)
        ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3] + ways[(i-3)%3];
    return ways[n%3];
}

int main(){
    cout << dynamic(4) << endl;
    cout << dynamicSpaceOptimized(4) << endl;
    return 0;
}