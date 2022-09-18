#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n){
	int LIS[n], len = 0;
	for(int i = 0; i < n; i++)
		LIS[i] = 1;
	for(int i = 1; i < n; i++){
		for(int j =  0; j < i; j++)
			if(arr[i] > arr[j] && (i-j) <= (arr[i] - arr[j]))
				LIS[i] = max(LIS[i], LIS[j] + 1);
		len = max(len, LIS[i]);
	}
	return n - len;
}

int main(){
	int arr[] = {1,2,6,5,4};
	int n = sizeof(arr)/sizeof(int);
	cout << dynamic(arr, n) << endl;
	return 0;
}
