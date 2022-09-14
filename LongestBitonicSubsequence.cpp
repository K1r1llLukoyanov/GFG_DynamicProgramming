#include <bits/stdc++.h>
using namespace std;

int lbs(int arr[], int n){
    int i, j;

    int *lis = new int[n];
    for(i = 0; i < n; i++)
        lis[i] = 1;

    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            if(arr[i] > arr[j])
                lis[i] = max(lis[i], 1 + lis[j]);

    int *lds = new int[n];
    for(i = 0; i < n; i++)
        lds[i] = 1;

    for(i = n-2; i >= 0; i--){
        for(j = n-1; j > i; j--){
            if(arr[i] > arr[j])
                lds[i] = max(1 + lds[j], lds[i]);
        }
    }

    int m = lis[0] + lds[0] - 1;
    for(i = 1; i < n; i++)
        m = max(m, lis[i] + lds[i]-1);
    return m;
}

int main(){
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(int);
    cout << "LBS: " << lbs(arr, n) << endl;
    return 0;
}