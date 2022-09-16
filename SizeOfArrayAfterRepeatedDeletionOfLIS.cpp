#include <bits/stdc++.h>
using namespace std;

queue<int> findLis(vector<int> arr){
    queue<int> ans = {};
    int n = arr.size();
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(arr[i-1] < arr[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    int i = n, j = n;
    int c = dp[i][j];
    while(c != 0){
        if(arr[i-1] == arr[j-1]){
            ans.push(arr[i-1]);
            i--;
            j--;
            c--;
        }
        else if(dp[i][j] == dp[i-1][j])
            i--;
        else if(dp[i][j] == dp[i][j-1])
            j--;
    }
    return ans;
}

int deleteLis(vector<int> arr){
    while(arr.size()){
        queue<int> q = findLis(arr);
        if(q.size() == 1)
            break;
        int j = q.front();
        for(int i = 0; i < arr.size() && q.size() > 0; i++){
            if(arr[i] == j){
                arr.erase(arr.begin()+i);
                i--;
                q.pop();
                if(q.size())
                    j = q.front();
            }
        }
    }
    return arr.size();
}

int main(){
    vector<int> arr = {5, 3, 2};
    cout << deleteLis(arr) << endl;
    return 0;
}