#include <bits/stdc++.h>
using namespace std;

void dynamic(vector<int> arr){
    int n = arr.size();
    int dp[n];
    dp[0] = arr[0];
    for(int i = 1; i < n; i++){
        dp[i] = arr[i];
        for(int j = 0; j < sqrt(i); j++){
            if((i+1)%(j+1) == 0)
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
    for(int i = 0; i < n; i++)
        cout << dp[i] << " ";
    cout << endl;
}

int main(){
    vector<int> arr = {2, 3, 1, 4, 6, 5};
    dynamic(arr);
    return 0;
}