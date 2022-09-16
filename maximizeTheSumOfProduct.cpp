#include <bits/stdc++.h>
using namespace std;

#define MAXN 10

int recursion(int arr[], int i, int j, int n, int memo[MAXN][MAXN]){
    if(i > j)
        return 0;
    else if(i == j)
        return n*arr[i];
    else if(memo[i][j] != 0)
        return memo[i][j];
    memo[i][j] = max(n*arr[i] + recursion(arr, i+1, j, n+1, memo), n*arr[j] + recursion(arr, i, j-1, n+1, memo));
    return memo[i][j];
}

int main(){
    int arr[] = { 1, 3, 1, 5, 2 };
    int n = sizeof(arr)/sizeof(int);
    int memo[MAXN][MAXN];
    memset(memo, 0, sizeof(memo));
    cout << recursion(arr, 0, n-1, 1, memo) << endl;
    return 0;
}