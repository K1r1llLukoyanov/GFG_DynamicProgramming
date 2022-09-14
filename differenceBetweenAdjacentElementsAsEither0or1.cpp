#include <bits/stdc++.h>
using namespace std;

int recursion(int a[], int i, int n, int p = INT_MIN){
	if(i < n){
		if(p == INT_MIN){
			return max(1 + recursion(a, i+1, n, a[i]), recursion(a, i+1, n, p));
		}
		
		if(abs(p - a[i]) == 0 || abs(p-a[i]) == 1)
			return max(1 + recursion(a, i+1, n, a[i]), recursion(a, i+1, n, p));
		else
			return recursion(a, i+1, n, p);
	}
	return 0;
}

int dynamic(int a[], int n){
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++)
			if(abs(a[i] - a[j]) == 0 || abs(a[i] - a[j]) == 1)
				dp[i] = max(dp[i], 1 + dp[j]);
	}
	int m = 1;
	int j = 0;
	for(int i = 1; i < n; i++)
		if(m < dp[i]){
			m = dp[i];
			j = i;
		}
	int r = m;
	int c = 0;
	int p = j;
	vector<int> res;
	while(c < r){
		if(dp[j] == m && (abs(a[j] - a[p]) == 0 || abs(a[j] - a[p]) == 1)){
			res.push_back(a[j]);
			m--;
			p = j;
			c++;
		}
		j--;
	}
	reverse(res.begin(), res.end());
	cout << "Sequence: ";
	for(auto &e: res)
		cout << e << " ";
	cout << endl;
	return r;
}

int main(){
	int arr[] = {-2, -1, 5, -1, 4, 0, 3};
	int n = sizeof(arr)/sizeof(int);
	cout << recursion(arr, 0, n, -1) << endl;
	cout << dynamic(arr, n) << endl;
	return 0;
}