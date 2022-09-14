#include <iostream>
#include <vector>
using namespace std;

bool recur(int div, vector<int> nums, int m, int sum){
    if(sum != 0 && sum % div == 0)
        return true;
    if(m < 0)
        return false;
    return recur(div, nums, m-1, sum) || recur(div, nums, m-1, sum + nums[m]);
}

bool dynamic(int div, vector<int> nums, int m){
    int dp[m+1][div+1];
    for(int i = 0; i <= m; i++){
        int d;
        if(i != 0)
            d = nums[i-1]%div;
        for(int j = 0; j <= div; j++){
            if(i == 0){
                if(j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
                continue;
            } 
            if(j == d)
                dp[i][j] = 1;
            else if(j == nums[i-1])
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-d];
        }
    }
    return dp[m][div]; 
}

int main(){
    vector<int> nums = {3, 1, 7, 5};
    int div = 10;
    int n = nums.size();
    if(dynamic(div, nums, n))
        cout << "Exist\n";
    else
        cout << "Doesn't exist\n";
    return 0;
}