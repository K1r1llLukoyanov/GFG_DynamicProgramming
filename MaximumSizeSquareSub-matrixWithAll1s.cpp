#include <bits/stdc++.h>
using namespace std;

#define R 6
#define C 5

void printMaxSubSquare(bool mat[R][C]){
	int dp[R+1][C+1];
	int m = 0;
	for(int i = 0; i <= R; i++){
		for(int j = 0; j <= C; j++){
			if(i == 0){
				dp[i][j] = 0;
				continue;
			}
			else if(j == 0){
				dp[i][j] = 0;
				continue;
			}
			
			if(mat[i-1][j-1] == 0)
				dp[i][j] = 0;
			else{
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
				m = max(m, dp[i][j]);
			}
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cout << 1 << " ";
		}
		cout << endl;
	}
}

int main()
{
	bool M[R][C] = {{0, 1, 1, 0, 1},
					{1, 1, 0, 1, 0},
					{0, 1, 1, 0, 1},
					{1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1},
					{0, 1, 1, 1, 1}};

	printMaxSubSquare(M);
	return 0;
}