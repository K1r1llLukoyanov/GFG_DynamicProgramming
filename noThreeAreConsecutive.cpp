#include <bits/stdc++.h>
using namespace std;

int maxsum(vector<int> a, int i, int n, int p, int c, int step){
    if(i < n){
        if(p == -1){
            return max(a[i] + maxsum(a, i+1, n, a[i], 1, 0), maxsum(a, i+1, n, -1, 0, 0));
        }
        if(c == 2){
            if(a[i] == p + step)
                return 0;
            else
                return (a[i] + maxsum(a, i+1, n, a[i], 1, 0), a[i] + maxsum(a, i+2, n, -1, 1, 0));
        }
        else{
            step = a[i] - p;
            return max(a[i] + maxsum(a, i+1, n, a[i], 2, step), a[i] + maxsum(a, i+2, n, -1, 1, 0));
        }
    }
    return 0;
}

int dynamic(vector<int> arr, int n){
    int sum[n];
    if(n >= 1)
        sum[0] = arr[0];
    if(n >= 2)
        sum[1] = sum[0] + arr[1];
    if(n > 2)
        sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2]));
        
    for(int i = 3; i < n; i++)
        sum[i] = max(arr[i] + arr[i-1] + sum[i-3], max(sum[i-1], sum[i-2] + arr[i]));

    return sum[n-1];
}

int main(){
    vector<int> arr = {100, 1000, 100, 1000, 1};
    int n = arr.size();
    cout << maxsum(arr, 0, n, -1, 0, 0) << endl;
    cout << dynamic(arr, n) << endl;
    return 0;
}