#include <bits/stdc++.h>
using namespace std;

int recursion(int n, map<int, int> &memo)
{
    if (memo.find(n) == memo.end())
    {
        if (n == 0)
            return 0;
        if(n == 1)
            return 1;

        int a = max(n / 2, recursion(n / 2, memo)), b = max(n / 3, recursion(n / 3, memo)), c = max(n / 4, recursion(n / 4, memo));

        memo[n] = a + b + c;
        
        return a + b + c;
    }
    return memo[n];
}

int dynamic(int n){
    int dp[n+1];
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i/2] + dp[i/3] + dp[i/4], i);
    }
    return dp[n];
}

int main()
{
    int n = 24;
    map<int, int> memo;
    cout << recursion(n, memo) << endl;
    cout << dynamic(n) << endl;
    return 0;
}