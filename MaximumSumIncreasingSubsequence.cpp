#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n){
    int lis[n];
    for(int i = 0; i < n; i++)
        lis[i] = arr[i];
    
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j])
                lis[i] = max(lis[i], arr[i]*lis[j]);
    
    int m = lis[0];
    for(int i = 1; i < n; i++)
        m = max(m, lis[i]);
    
    return m;
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(int);
    cout << "Max increasing sum: " << dynamic(arr, n) << endl;
    return 0;
}