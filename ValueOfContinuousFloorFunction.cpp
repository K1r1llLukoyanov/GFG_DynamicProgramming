#include <iostream>
using namespace std;

void dynamic(int arr[], int n){
	int m = arr[0];
	for(int i = 1; i < n; i++)
		if(m < arr[i])
			m = arr[i];
	int dp[m+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= m; i++)
		dp[i] = i + dp[i/2];
	for(int i = 0; i < n; i++)
		cout << dp[arr[i]] << " ";
	cout << endl;
}

int main(){
	int arr[] = {6, 8};
	int n = sizeof(arr)/sizeof(int);
	dynamic(arr, n);
	return 0;
}
