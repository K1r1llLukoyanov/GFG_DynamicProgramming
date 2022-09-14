#include <iostream>
#include <vector>
using namespace std;

bool dynamic(int sum, vector<int> nums, int m){
    int dp[2][sum+1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= sum; j++){
            if(j == 0)
                dp[i%2][j] = true;
            else if(i == 0)
                dp[i%2][j] = false;
            else if(nums[i-1] > j)
                dp[i%2][j] = dp[(i+1)%2][j];
            else
                dp[i%2][j] = max(dp[(i+1)%2][j], dp[(i+1)%2][j-nums[i-1]]);
        }
    }
    return dp[m%2][sum];
}

int main(){
    vector<int> nums = { 6, 2, 5 };
    int sum = 7;
    int m = nums.size();
    if (dynamic(sum, nums, m) == true)
        cout <<"There exists a subset with given sum";
    else
        cout <<"No subset exists with given sum";
    return 0;
}