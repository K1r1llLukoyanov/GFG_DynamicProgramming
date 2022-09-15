#include <bits/stdc++.h>
using namespace std;

int recursion(int a, int b, int i, int n){
    if(i > n)
        return 1;
    if(i == 1)
        return recursion(0, 1, 2, n) + recursion(1, 0, 2, n) + recursion(0, 0, 2, n);
    if(a == 0 && b == 0)
        return recursion(0, 1, i+1, n) + recursion(1, 0, i+1, n) + recursion(0, 0, i+1, n);
    else if(a == 0)
        return recursion(1, 0, i+1, n) + recursion(0, 0, i+1, n);
    return recursion(0, 1, i+1, n) + recursion(0, 0, i+1, n);
}

int dynamic(int n){
    int dp[2][n+1];
    dp[0][1] = 1;
    dp[1][1] = 2;
    for(int i = 2; i <= n; i++){
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1]*2 + dp[1][i-1];
    }
    return dp[0][n] + dp[1][n];
}

int better_dynamic(int n){
    long long A[n+1];
    A[0] = 1;
    A[1] = 3;
    A[2] = 7;
    for(int i = 3; i <= n; i++)
        A[i] = 2*A[i-1] + A[i-2];
    return A[n];
}

int main(){
    int n = 5;
    cout << recursion(0, 0, 1, n) << endl;
    cout << dynamic(n) << endl;
    cout << better_dynamic(n) << endl;
    return 0;
}