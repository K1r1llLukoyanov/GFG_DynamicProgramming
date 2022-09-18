#include <bits/stdc++.h>
using namespace std;

int recursion(int arr[], int n, int sum, int k){
	int a = 0;
	for(int j = 0; j < n; j++){
		if(sum + arr[j] == k)
			a += 1;
		else if(sum + arr[j] < k)
			a += recursion(arr, n, sum + arr[j], k);
	}
	return a;
}

int dynamic(int arr[], int n, int sum){
	int dp[sum+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= sum; i++){
		for(int j = 0; j < n; j++){
			if(i >= arr[j])
				dp[i] += dp[i-arr[j]];
		}
	}
	return dp[sum];
}

int main(){
	int arr[] = {12, 3, 1, 9}, N = 14;
	int n = sizeof(arr)/sizeof(int);
	cout << dynamic(arr, n, N) << endl;
	cout << recursion(arr, n, 0, N) << endl;
	return 0;
}
