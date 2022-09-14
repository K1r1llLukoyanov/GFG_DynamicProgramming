#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> a, int i, int j, int n){
    if(i < n && j < n){
        if(a[i] < a[j])
            return 1 + recursion(a, j, j + 1, n);
        else if(i > j)
            return 0;
        else
            return max(recursion(a, i+1, i+1, n), recursion(a, i, j+1, n));
    }
    return 1;
}

int dynamic(vector<int> a){
    int n = a.size();
    int dp[n];
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] > a[j])
                dp[i] = max(1 + dp[j], dp[i]);
        }
    }
    int m = 0;
    int j = 0;
    for(int i = 0; i < n; i++)
        if(m < dp[i]){
            m = max(m, dp[i]);
            j = i;
        }
    
    vector<int> LIS;
    while(dp[j] != 1){
        LIS.push_back(a[j]);
        int c = j-1;
        while(dp[c] != dp[j] - 1)
            c--;
        j = c;
    }
    LIS.push_back(a[j]); 
    reverse(LIS.begin(), LIS.end());
    cout << "LIS: ";
    for(auto &a: LIS)
        cout << a << " ";
    cout << endl;
    return m;
}

int main(){
    vector<int> a = {3, 10, 2, 1, 20};
    int n = a.size();
    cout << recursion(a, 0, 0, n) << endl;
    cout << dynamic(a) << endl;
    return 0;
}