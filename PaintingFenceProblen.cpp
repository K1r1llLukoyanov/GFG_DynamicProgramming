#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int k, int seq){
	if(n == 0)
		return 0;
	if(n == 1){
		if(seq == 1)
			return k;
		else if(seq == 2)
			return 1;
	}
	if(seq == 0)
		return recursion(n-1, k, seq+1)*k;
	else if(seq == 1)
		return recursion(n-1, k, seq+1) + recursion(n-1, k, 1)*(k-1);
	return recursion(n-1, k, 1)*(k-1);
}

long countWays(int n, int k){
	long dp[n+1];
	memset(dp, 0, sizeof(dp));
	long long mod = 1000000007;
	dp[1] = k;
	dp[2] = k*k;
	for(int i = 3; i <= n; i++)
		dp[i] = ((k-1)*(dp[i-1] + dp[i-2]))%mod;
	return dp[n];
}

int main(){
	int n = 2;
	int k = 4;
	cout << countWays(n,k) << endl;
	return 0;
}
