#include <iostream>
using namespace std;

void dynamic(int arr[], int n){
	int dp[n];
	dp[n-1] = 1;
	for(int i = n-2; i >= 0; i--){
		if(arr[i]*arr[i+1] < 0)
			dp[i] = dp[i+1] + 1;
		else
			dp[i] = 1;
	}
	for(int i = 0; i < n; i++)
		cout << "index " << i << " = " << dp[i] << endl;
}


int main(){
	int arr[] = {-5, -1, -1, 2, -2, -3};
	int n = sizeof(arr)/sizeof(int);
	dynamic(arr, n);
	return 0;
}
