#include <bits/stdc++.h>
using namespace std;

int recur(int begin, int mid, int end, vector<int> rod, map<int, int> &memo){
    if(mid > end)
        return 0;
    if(memo.find(end-begin) != memo.end())
        return memo[end-begin];
    
    int val = max(recur(begin, mid+1, end, rod, memo), rod[mid-begin] + recur(mid+1, mid+1, end, rod, memo));
    memo[end-begin] = val;
    return val;
}

int dynamic(int n, vector<int> rod){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = rod[0];
    for(int i = 2; i <= n; i++){
        int mxm = 0;
        for(int j = 1; j <= i/2; j++){
            mxm = max(mxm, dp[j] + dp[i-j]);
        }
        dp[i] = max(mxm, rod[i-1]);
    }
    return dp[n];
}

int main(){
    vector<int> rod = {3,5,8,9,10,17,17,20};
    int length = rod.size();
    map<int, int> memo;
    cout << recur(0, 0, length-1, rod, memo) << endl;
    cout << dynamic(length, rod) << endl;
    return 0;
}