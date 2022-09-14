#include <bits/stdc++.h>
using namespace std;

int recursion(int a[], int i, int n, int p){
    if(i < n){
        if(p == -1){
            return max(1 + recursion(a, i+1, n, a[i]), recursion(a, i+1, n, -1));
        }
        if(abs(a[i]-p) != 1){
            return recursion(a, i+1, n, p);
        }
        else{
            return max(1 + recursion(a, i+1, n, a[i]), recursion(a, i+1, n, p));
        }
    }
    return 0;
}

int dynamic(int a[], int n){
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(abs(a[j]-a[i]) == 1)
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    int m = 1;
    int j = 0;
    for(int i = 1; i < n; i++)
        if(m < dp[i]){
            m = dp[i];
            j = i;
        }
    
    vector<int> res;
    int r = m;
    int c = 0;
    while(c < r){
        if(dp[j] == m){
            res.push_back(a[j]);
            m--;
            c++;
        }
        j--;
    }
    res.push_back(a[j]);
    reverse(res.begin(), res.end());
    cout << "Sequence: ";
    for(auto &e: res)
        cout << e << " ";
    cout << endl;
    return r;
}

int main(){
    int arr[] = {1, 2, 3, 2, 3, 7, 2, 1};
    int n = sizeof(arr)/sizeof(int);
    cout << recursion(arr, 0, n, -1) << endl;
    cout << dynamic(arr, n) << endl;
    return 0;
}