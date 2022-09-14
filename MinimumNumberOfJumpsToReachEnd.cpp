#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n){
    int dp[n];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n && j <= i+arr[i]; j++){
            if(dp[j] == -1)
                dp[j] = dp[i] + 1;
            else
                dp[j] = min(dp[i] + 1, dp[j]);
        }
    }
    return dp[n-1];
}

int main(){
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr)/sizeof(int);
    cout << dynamic(arr, n) << endl;
    return 0;
}