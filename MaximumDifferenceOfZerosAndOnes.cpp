#include <bits/stdc++.h>
using namespace std;

int dynamic(string s){
	int n = s.length();
	int dp[n];
	if(s[0] == '1')
		dp[0] = -1;
	else
		dp[0] = 1;

	int m = -1;
	for(int i = 1; i < n; i++){
		if(s[i] == '0')
			dp[i] = max(1, dp[i-1] + 1);
		else
			dp[i] = max(-1, dp[i-1] - 1);
		
		if(dp[i] > m)
			m = dp[i];
	}
	return m;
}

int main(){
	string s = "1111";
	cout << dynamic(s) << endl;
	return 0;
}
