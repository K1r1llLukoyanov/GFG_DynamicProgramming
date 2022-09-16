#include <bits/stdc++.h>
using namespace std;

int dynamic(int N){
	int n = 2*N;
	int dp[n+1] = {0};
	dp[0] = 1;
	dp[2] = 1;
	for(int i = 4; i <= n; i+=2){
		for(int j = 0; j < i-1; j+=2)
			dp[i] += (dp[j]*dp[i-j-2]);
	}
	return dp[n];
}

int main(){
	int N = 4;
	cout << dynamic(N) << endl;
	return 0;
}