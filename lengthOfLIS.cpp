#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums, int i, int n, int prev, int curr){
    if(i == n-1)
        return 1;
    
    int max_len = 1;
    
    if(nums[curr] < nums[i+1]){
        max_len = max(max_len, max(lengthOfLIS(nums, i+1, n, i, curr+1), 1 + lengthOfLIS(nums, i+1, n, i, curr+1)));
    }
    else{
        max_len = max(max_len, lengthOfLIS(nums, i+1, n, prev, curr+1));
        if(i != 0 && nums[i+1] > nums[prev]){
            max_len = max(max_len, lengthOfLIS(nums, i+1, n, prev, prev));
        }
    }

    cout << i << ") " << nums[i] << ": " << max_len << endl;

    return max_len;
}


int main(){
    vector<int> nums = {3,1,2};
    int n = nums.size();
    int curr = nums[0];
    int len = lengthOfLIS(nums, 0, n, 0, 0);
    cout << "length of LIS: " << len << endl;
    return 0;
}