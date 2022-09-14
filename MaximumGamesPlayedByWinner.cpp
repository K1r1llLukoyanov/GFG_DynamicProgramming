#include <bits/stdc++.h>
using namespace std;

int recursion(int N){
	if(N == 1)
		return 0;
	else if(N == 2)
		return 1;
	else if(N == 3 || N == 4)
		return 2;
	return recursion(N/2) + recursion(N/2 + 1);
}

int dynamic(int N){
	if(N == 1)
		return 0;
	int dp[N];
	dp[0] = 1;
	dp[1] = 2;
	int i = 1;
	while(dp[i++] < N){
		dp[i] = dp[i-1] + dp[i-2];
	}
	if(dp[i-1] == N)
		return i-1;
	return i-2;
}

int main(){
	cout << recursion(10) << endl;
	return 0;
}