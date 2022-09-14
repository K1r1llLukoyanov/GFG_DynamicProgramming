#include <bits/stdc++.h>
using namespace std;

int recursion(int N, int a, int b, int c){
	if(N < 0)
		return INT_MIN;
	else if(N == 0)
		return 0;

	return max(1 + recursion(N-a, a, b, c), max(1 + recursion(N-b, a, b, c), 1 + recursion(N-c, a, b, c)));
}

int dynamic(int N, int a, int b, int c){
	int dp[N+1];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < N; i++){
		if(dp[i] != -1){
			if(i + a <= N)
				dp[i+a] = max(dp[i+a], 1 + dp[i]);
			if(i + b <= N)
				dp[i+b] = max(dp[i+b], 1 + dp[i]);
			if(i + c <= N)
				dp[i+c] = max(dp[i+c], 1 + dp[i]);
		}
	}	
	return dp[N] == -1 ? 0 : dp[N];
}

int main(){
	int N = 14, a = 5, b = 5, c = 5;
	cout << recursion(N, a, b, c) << endl;
	cout << dynamic(N, a, b, c) << endl;
	return 0;
}