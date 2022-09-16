#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n){
    int sum = arr[0];
    int minsum = arr[0];
    for(int i = 1; i < n; i++){
        if(sum + arr[i] > arr[i])
            sum = arr[i]; 
        else
            sum = arr[i] + sum;
        minsum = min(sum, minsum);
    }
    return minsum;
}

int main(){
    int arr[] = {2, 6, 8, 1, 4};
    int n = sizeof(arr)/sizeof(int);
    cout << dynamic(arr, n) << endl;
    return 0;
}