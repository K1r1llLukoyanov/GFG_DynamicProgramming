#include <bits/stdc++.h>
using namespace std;

int recursion(int arr[], int i, int n){
    if(i < n)
        return max(arr[i] + recursion(arr, i+2, n), recursion(arr, i+1, n));
    return 0;
}

int dynamic(int arr[], int n){
    int dp[n];
    dp[0] = arr[0], dp[1] = max(arr[1], arr[0]);
    for(int i = 2; i < n; i++){
        dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}

int dynamicSpaceOptimized(int arr[], int n){
    if(n == 1)
        return arr[0];
    if(n == 2)
        return arr[1];
    
    int value1 = arr[0];
    int value2 = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++){
        int temp = value2;
        value2 = max(value1 + arr[i], value2);
        value1 = temp;
    }
    return value2;
}

int main(){
    int hval[] = {6, 7, 1, 3, 8, 2, 4};
    int n = sizeof(hval)/sizeof(int);
    cout << dynamic(hval, n) << endl;
    cout << recursion(hval, 0, n) << endl;
    cout << dynamicSpaceOptimized(hval, n) << endl;
    return 0;
}