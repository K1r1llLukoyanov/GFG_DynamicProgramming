#include <bits/stdc++.h>
using namespace std;

class Pair{
public:
	int a;
	int b;
};

int recursion(Pair arr[], int i, int n, int prev){
	if(i < n){
		if(prev == -1){
			return max(1 + recursion(arr, i+1, n, i), recursion(arr, i+1, n, prev));
		}
		if(arr[prev].b < arr[i].a)
			return max(1 + recursion(arr, i+1, n, i), recursion(arr, i+1, n, prev));
		else
			return recursion(arr, i+1, n, i);
	}
	return 0;
}

int dynamic(Pair arr[], int n){
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(arr[i].a > arr[j].b)
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}
	int m = 1;
	int index = 0;
	for(int i = 1; i < n; i++)
		if(m < dp[i]){
			m = dp[i];
			index = i;
		}
	int r = m;
	int prev = index;
	vector<Pair> res = {arr[index--]};
	m-=1;
	while(m != 0){
		if(dp[index] == m && arr[index].b < arr[prev].a){
			res.push_back(arr[index]);
			prev = index;
			m-=1;
		}
		index--;
	}
	reverse(res.begin(), res.end());
	cout << "Max length sequence: ";
	for(auto &e: res){
		cout << "{" << e.a << ", " << e.b << "} ";
	}
	cout << endl;
	return r;
}

int main(){
	Pair arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60} };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Max length: " << dynamic(arr, n) << endl;
	return 0;
}