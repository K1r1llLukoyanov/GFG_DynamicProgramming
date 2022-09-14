#include <bits/stdc++.h>
using namespace std;

int recursion(int left){
    if(left < 0)
        return 0;
    else if(left == 0)
        return 1;
    return recursion(left-1) + recursion(left-2);
}

int dynamic(int left){
    int dp[left+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= left; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[left];
}

int main(){
    int n = 8;
    cout << recursion(n) << endl;
    cout << dynamic(n) << endl;
    return 0;
}
