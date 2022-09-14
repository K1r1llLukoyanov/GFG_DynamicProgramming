#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n, int k){
    int sum = arr[0];
    int maxsum = arr[0];
    for(int i = 1; i < n*k; i++){
        if(sum + arr[i%n] > arr[i%n])
            sum += arr[i%n];
        else
            sum = arr[i%n];
        
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int main(){
    int arr[] = {-1, -2, -3};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    cout << dynamic(arr, n, k) << endl;
    return 0;
}