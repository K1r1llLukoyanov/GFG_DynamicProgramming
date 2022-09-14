#include <bits/stdc++.h>
using namespace std;

int dynamic(vector<vector<int>> vec){
	int n = vec.size();
	for(int i = 1; i < n; i++){
		int m = vec[i].size();
		for(int j = 0; j < m; j++){
			if(j == 0)
				vec[i][j] = vec[i-1][j] + vec[i][j];
			else if(j == m-1)
				vec[i][j] = vec[i-1][j-1] + vec[i][j];
			else
				vec[i][j] = max(vec[i-1][j], vec[i-1][j-1]) + vec[i][j];
		}
	}
	int m = vec[n-1][0], index = 0;
	int d = vec[n-1].size();
	for(int i = 1; i < d; i++)
		if(m < vec[n-1][i]){
			m = vec[n-1][i];
			index = i;
		}
	int r = m;
	d = n-1;
	vector<int> path;
	while(d > 0){
		if(index == 0)
			path.push_back(vec[d][index] - vec[d-1][index]);
		else if(index == vec[d].size() - 1)
			path.push_back(vec[d][index] - vec[d-1][--index]);
		else{
			if(vec[d-1][index] < vec[d-1][index-1])
				path.push_back(vec[d][index] - vec[d-1][--index]);
			else
				path.push_back(vec[d][index] - vec[d-1][index]);
		}
		d-=1;
	}
	path.push_back(vec[0][0]);
	reverse(path.begin(), path.end());
	cout << "Path with max sum: ";
	for(auto &e: path)
		cout << e << " ";
	cout << endl;

	return r;
}

int main(){
	vector<vector<int>> vec = {{2}, {4, 1}, {1, 2, 7}};
	cout << "Max sum of path: " << dynamic(vec) << endl;
	return 0;
}