#include <bits/stdc++.h>
using namespace std;

int dynamic(int arr[], int n){
	int leftIndex = 0, maxLeftIndex = 0;
	int rightIndex = 0, maxRightIndex = 0;
	int maxsum = arr[0];
	int sum = arr[0];
	for(int i = 1; i < n; i++){
		if(sum + arr[i] > arr[i]){
			sum = arr[i] + sum;
			rightIndex++;
		}
		else{
			sum = arr[i];
			leftIndex = i;
			rightIndex = i;
		}
		if(sum > maxsum){
			maxsum = sum;
			maxLeftIndex = leftIndex;
			maxRightIndex = rightIndex;
		}
	}
	cout << "Max sum: " << maxsum << endl;
	cout << "Subarray with max sum: ";
	for(int i = maxLeftIndex; i <= maxRightIndex; i++)
		cout << arr[i] << " ";
	cout << endl;
	return maxRightIndex-maxLeftIndex+1;
}

int main(){
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(arr)/sizeof(int);
	cout << dynamic(arr, n) << endl;	
	return 0;
}