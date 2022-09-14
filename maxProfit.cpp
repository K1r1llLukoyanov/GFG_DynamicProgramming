#include <iostream>
using namespace std;

int main(){
    int prices[6] = {1,3,2,8,4,9}, fee = 2;
    int size = sizeof(prices)/sizeof(int);
    int dp[size+1][2];
    dp[size][0] = 0, dp[size][1] = 0;
    
    for(int pos = size-1; pos >= 0; pos--){
        dp[pos][0] = max(dp[pos+1][1]-prices[pos], dp[pos+1][0]);
        dp[pos][1] = max(dp[pos+1][0]+prices[pos]-fee, dp[pos+1][1]);
    }

    cout << dp[0][0] << endl;
    return 0;
}
