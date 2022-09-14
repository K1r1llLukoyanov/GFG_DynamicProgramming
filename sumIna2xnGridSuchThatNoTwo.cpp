#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> arr, int i, int n){
    if(i < n){
        return max(arr[0][i] + recursion(arr, i+2, n), arr[1][i] + recursion(arr, i+2, n));
    }
    return 0;
}

int dynamic(vector<vector<int>> arr){
    int n = arr[0].size();
    int dp[n];
    dp[0] = max(arr[0][0], arr[1][0]);
    dp[1] = max(arr[0][1], arr[1][1]);
    for(int i = 2; i < n; i++)
        dp[i] = max(arr[0][i], arr[1][i]) + dp[i-2];
    return dp[n-1];
}

int main(){
    vector<vector<int>> arr = {{1, 4, 5}, {2, 0, 0}};
    int n = arr[0].size();
    cout << dynamic(arr) << endl;
    cout << recursion(arr, 0, n) << endl;
    return 0;
}