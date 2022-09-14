#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n){
    int mx = -1;
    for(int i = 0; i < n; i++)
        mx = max(mx, arr[i]);
    
    int freq[mx+1];

    memset(freq, 0, sizeof(freq));

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;
    
    int ans = 0, i = mx;

    while(i > 0){
        if(freq[i] > 0){
            ans+=i;
            freq[i-1]--;
            freq[i+1]--;
            freq[i]--;
        }
        else
            i--;
    }
    return ans;
}

int main(){
    int a[] = {1, 2, 2, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    cout << dynamic(a, n) << endl;
    return 0;
}