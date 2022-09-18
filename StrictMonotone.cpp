#include <bits/stdc++.h>
using namespace std;

int dynamic(int N){
	int dp[N][9];
	memset(dp, 0, sizeof(dp));
	
	for(int i = 0; i < 9; i++)
		dp[0][i] = i+1;

	for(int i = 1; i < N; i++)
		for(int j = 1; j < 9; j++)
			dp[i][j] = dp[i-1][j-1] + dp[i][j-1];

	return dp[N-1][8];
}

int main(){
	cout << dynamic(2) << endl;
	return 0;
}
