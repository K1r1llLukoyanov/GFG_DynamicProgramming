#include <iostream>
#include <vector>
using namespace std;

int subset(int n, vector<int> nums, int m){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    if(m < 0)
        return 0;
    return max(subset(n-nums[m], nums, m-1), subset(n, nums, m-1));
}

bool dynamic(int n, vector<int> nums, int m){
    int dp[m+1][n+1];
    dp[0][0] = 1; 
    for(int i = 0; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(i == 0){
                dp[i][j] = 0;
                continue;
            }
            if(j < nums[i-1])
                dp[i][j] = dp[i-1][j];
            else if(j == nums[i-1])
                dp[i][j] = 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]]);
        }
    }
    return dp[m][n];
}

int main(){
    vector<int> nums = {1, 5, 3, 7, 4};
    int sum = 12;
    int tr = subset(sum, nums, nums.size() - 1);
    int tr2 = dynamic(sum, nums, nums.size());
    if(tr)
        cout << "YES\n";
    else
        cout << "NO\n";
    if(tr2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
