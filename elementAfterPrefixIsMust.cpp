#include <bits/stdc++.h>
using namespace std;

int recursion(int a[], int i, int n, int prev, int j, int k){
	if(i < n){
		if(i > j)
			return 0;
		if(a[i] > a[k])
			return recursion(a, i+1, n, prev, j, k);
		if(prev == -1)
			return max(a[i] + recursion(a, i+1, n, a[i], j, k), recursion(a, i+1, n, prev, j, k));
		if(a[i] > prev)
			return max(a[i] + recursion(a, i+1, n, a[i], j, k), recursion(a, i+1, n, prev, j, k));
		else
			return recursion(a, i+1, n, prev, j, k);
	}
	return 0;
}

int dynamic(int arr[], int n, int j, int k){
	int dp[n];
	for(int i = 0; i <= j; i++){
		if(arr[i] < arr[k])
			dp[i] = arr[i];
		else{
			dp[i] = 0;
			continue;
		}
		for(int z = 0; z < i; z++){
			if(arr[i] > arr[z])
				dp[i] = max(dp[i], arr[i] + dp[z]);
		}
	}
	int m = dp[0];
	int index = 0;
	vector<int> res = {arr[k]};
	for(int i = 1; i <= j; i++){
		if(m < dp[i]){
			m = dp[i];
			index = i;
		}
	}
	int r = m;
	while(m != 0){
		if(dp[index] == m){
			res.push_back(arr[index]);
			m-=arr[index];
		}
		index--;
	}
	reverse(res.begin(), res.end());
	cout << "Sequence: ";
	for(auto &e: res)
		cout << e << " ";
	cout << endl;
	return r + arr[k];
}


int main(){
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr)/sizeof(int);
	int i = 2, k = 5;
	cout << recursion(arr, 0, n, -1, i, k) + arr[k] << endl;
	cout << dynamic(arr, n, i, k) << endl;
	return 0;
}