#include <bits/stdc++.h>
using namespace std;

int recursion(int a[], int i, int j, int k){
    if(i >= j)
        return 0;
    if(a[j] - a[i] > k)
        return min(1 + recursion(a, i+1, j, k), 1 + recursion(a, i, j-1, k));
    else
        return 0;
}

int dynamic(int a[], int n, int k){
    int m = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(a[j] - a[i] <= k){
                m = min(i + n-j-1, m);
                break;
            }
        }
    }
    return m == INT_MAX ? -1 : m;
}

int main(){
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20}, k = 4;
    int n = sizeof(a)/sizeof(int);
    sort(a, a+n);
    cout << recursion(a, 0, n-1, k) << endl;
    cout << dynamic(a, n, k) << endl;
    return 0;
}