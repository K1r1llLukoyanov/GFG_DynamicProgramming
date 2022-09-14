#include <bits/stdc++.h>
using namespace std;

void display(vector<int> p){
    for(int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << "\n";
}

void recur(vector<int> nums, int n, int left, vector<int> set){
    if(left < 0)
        return;
    else if(left == 0){
        for(auto &a: set)
            cout << a << " ";
        cout << endl;
        return;
    }
    if(n < 0)
        return;
    recur(nums, n-1, left, set);
    set.push_back(nums[n]);
    recur(nums, n-1, left - nums[n], set);
}

void printSubsetsRec(vector<vector<int>> dp, vector<int> nums, int sum, int n, int i, vector<int> p){
    if(sum == 0 || dp[i][sum] == 0){
        display(p);
        return;
    }
    if(i == 0)
        return;
    if(i < n && dp[i+1][sum] == dp[i][sum])
        return;
    if(dp[i][sum] == dp[i-1][sum]){
        printSubsetsRec(dp, nums, sum, n, i-1, p);
    }
    else{
        p.push_back(nums[i-1]);
        printSubsetsRec(dp, nums, sum-nums[i-1], n, i-1, p);
    }
}

void dynamic(vector<int> nums, int n, int sum){
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(i == 0){
                if(j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
                continue;
            }
            if(j == 0){
                if(i != 0)
                    dp[i][j] = 0;
                continue;
            }
            if(j < nums[i-1])
                dp[i][j] = dp[i-1][j];
            else if(j == nums[i-1])
                dp[i][j] = dp[i-1][j] + 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    printSubsetsRec(dp, nums, sum, n, n, {});
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int sum = 10;
    int n = nums.size();
    recur(nums, n-1, sum, {});
    dynamic(nums, n, sum);
    return 0;
}
