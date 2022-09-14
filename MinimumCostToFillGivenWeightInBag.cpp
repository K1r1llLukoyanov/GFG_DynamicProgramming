#include <bits/stdc++.h>
using namespace std;

int dynamic(int cost[], int W){
    int dp[W+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = cost[0];
    for(int i = 2; i <= W; i++){
        int min_cost = cost[i-1];
        for(int j = 1; j < i; j++){
            if(cost[j-1] != -1)
                min_cost = min(dp[i-j] + cost[j-1], min_cost);
        }
        dp[i] = min_cost;
    }
    
    return dp[W];
}

int main(){
    int W = 5;
    int cost[] = {1, 2, 3, 4, 5};
    cout << dynamic(cost, W) << endl;
    return 0;
}