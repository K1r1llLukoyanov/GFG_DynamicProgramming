#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n){
    int i, j;
    int lis[n];
    for(i = 0; i < n; i++)
        lis[i] = arr[i];
    
    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            if(arr[i] > arr[j])
                lis[i] = max(lis[i], arr[i] + lis[j]);
    
    int lds[n];
    
    for(i = 0; i < n; i++)
        lds[i] = arr[i];

    for(i = n-2; i >= 0; i--)
        for(j = n-1; j > i; j--)
            if(arr[i] > arr[j])
                lds[i] = max(lds[i], arr[i] + lds[j]);
    
    int maxsum = lis[0] + lds[0] - arr[0];
    
    for(i = 1; i < n; i++)
        maxsum = max(maxsum, lis[i] + lds[i] - arr[i]);

    return maxsum;
}

int main(){
    int arr[] = {1, 15, 51, 45, 33, 100, 12, 18, 9};
    int n = sizeof(arr)/sizeof(int);
    cout << "Max LBS sum: " << dynamic(arr, n) << endl;
    return 0;
}