#include <bits/stdc++.h>
using namespace std;

int dynamic(vector<int> nums, int n){
    int dp[n];
    dp[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        int mxm = 0;
        for(int j = i+1; j < n; j++){
            if(nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0)
                mxm = max(mxm, dp[j]);
        }
        dp[i] = 1 + mxm;
    }
    return *max_element(dp, dp+n);
}

int main(){
    vector<int> nums = { 1, 3, 6, 13, 17, 18 };
    int n = nums.size();
    cout << dynamic(nums, n) << endl;  
    return 0;
}