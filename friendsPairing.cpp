#include <iostream>
using namespace std;

int friends(int n){
    if(n < 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return friends(n-1) + (friends(n-2))*(n-1);
}

int dynamic(int n){
    int dp[n+1];
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2]*(i-1);
    return dp[n];
}

int main(){
    int n = 4;
    cout << dynamic(n) << endl;
    return 0;
}