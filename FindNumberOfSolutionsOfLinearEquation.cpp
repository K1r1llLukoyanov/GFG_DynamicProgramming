#include <bits/stdc++.h>
using namespace std;

int recursion(int coeff[], int start, int end, int rhs){
    if(rhs == 0)
        return 1;
    int result = 0;
    for(int i = start; i <= end; i++)
        if(coeff[i] <= rhs)
            result += recursion(coeff, i, end, rhs-coeff[i]);
    return result;
}

int dynamic(int arr[], int n, int rhs){
    int dp[rhs+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= rhs; j++)
            dp[j] += dp[j - arr[i]];
    }
    return dp[rhs];
}

int main(){
    int coeff[] = {2, 2, 5};
    int rhs = 4;
    cout << recursion(coeff, 0, 1, rhs) << endl;
    cout << dynamic(coeff, 3, rhs) << endl;
    return 0;
}