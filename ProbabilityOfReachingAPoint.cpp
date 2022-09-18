#include <bits/stdc++.h>
using namespace std;

int main(){
	int N = 5;
	float P = 0.20;

	float a[N+5];
	a[0] = 1;
	a[1] = 0;
	a[2] = P;
	for(int i = 3; i <= N; i++)
		a[i] = a[i-2]*P + a[i-3]*(1-P);
	
	cout << a[N] << endl;
	return 0;
}
