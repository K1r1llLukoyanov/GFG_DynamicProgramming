#include <bits/stdc++.h>
using namespace std;

double dynamic(vector<vector<int>> vec){
	int n = vec.size(), m = vec[0].size();
	double dp[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 && j == 0){
				dp[0][0] = vec[i][j];
				continue;
			}
			if(i > 0 && j > 0)
				dp[i][j] = max(dp[i-1][j] + vec[i][j], dp[i][j-1] + vec[i][j]);
			else if(i > 0)
				dp[i][j] = (dp[i-1][j]+vec[i][j]);
			else if(j > 0)
				dp[i][j] = (dp[i][j-1]+vec[i][j]);
		}
	}
	return dp[n-1][m-1]/double(n+m-1);
}

int main(){
	vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
	cout << dynamic(arr) << endl;
	return 0;
}