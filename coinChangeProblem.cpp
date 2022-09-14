#include <bits/stdc++.h>
using namespace std;

int change(int moneyleft, vector<int> coins, int n, vector<int> sol){
	if(moneyleft < 0)
        return 0;
    else if(moneyleft == 0){
        for(auto &a: sol)
            cout << a << " ";
        cout << endl;
        return 1;
    }
    if(n <= 0)
        return 0;

    int sum = 0;
    sol.push_back(coins[n-1]);
    sum += change(moneyleft - coins[n-1], coins, n, sol);
    sol.pop_back();
    sum += change(moneyleft, coins, n-1, sol);
    return sum;
}

int dynamic(int moneyleft, vector<int> coins, int n){
    int dp[n+1][moneyleft+1];
   	for(int i = 0; i <= n; i++){
   		for(int j = 0; j <= moneyleft; j++){
   			if(i == 0){
   				dp[i][j] = 0;
   				if(j == 0)
                    dp[i][j] = 1;
                continue;
   			}
   			if(j == 0){
                if(i != 0)
                    dp[i][j] = 0;
                continue;
   			}
   			if(j < coins[i-1])
   				dp[i][j] = dp[i-1][j];
   			else if(j == coins[i-1])
   				dp[i][j] = dp[i-1][j] + 1;
   			else
   				dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
   		}
   	}
   	return dp[n][moneyleft];
}

int main(){
	int n = 25;
	vector<int> coins = {2, 5, 3, 6};
	vector<int> sol;
	int ways = change(n, coins, 4, sol);
	int ways2 = dynamic(n, coins, 4);
	cout << "Checker: " << ways << endl;
	cout << "Checked value: " << ways2 << endl;
	return 0;
}
