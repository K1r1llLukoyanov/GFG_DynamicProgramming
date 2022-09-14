#include <bits/stdc++.h>
using namespace std;

int recursion(int arr[], int i, int n, int needToPair, int k){
	if(i < n){
		if(needToPair == -1)
			return max(arr[i] + recursion(arr, i+1, n, arr[i], k), recursion(arr, i+1, n, needToPair, k));
		else{
			if(abs(arr[i]-needToPair) < k)
				return max(arr[i] + recursion(arr, i+1, n, -1, k), recursion(arr, i+1, n, needToPair, k));
			else
				return recursion(arr, i+1, n, needToPair, k);
		}
	}
	if(needToPair == -1)
		return 0;
	else
		return -needToPair;
}

int dynamic(int arr[], int n, int k){
	int dp[n];
	dp[0] = 0;
	for(int i = 1; i < n; i++){
		dp[i] = dp[i-1];
		if(arr[i] - arr[i-1] < k){
			if(i>=2)
				dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
			else
				dp[i] = max(dp[i], arr[i] + arr[i-1]);
		}
	}
	return dp[n-1];
}

int main(){
	int arr[] = {3, 5, 10, 15, 17, 12, 9};
	int n = sizeof(arr)/sizeof(int);
	sort(arr, arr+n);
	int k = 4;
	cout << dynamic(arr, n, k) << endl;
	return 0;
}