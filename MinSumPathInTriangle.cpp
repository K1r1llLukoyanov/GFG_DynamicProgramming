#include <bits/stdc++.h>
using namespace std;

int dynamic(vector<vector<int>> tri){
	int n = tri.size();
	for(int i = 1; i < n; i++){
		for(int j = 0; j < tri[i].size(); j++){
			if(j == 0)
				tri[i][j] = tri[i][j] + tri[i-1][j];
			else if(j == tri[i].size() - 1)
				tri[i][j] = tri[i][j] + tri[i-1][j-1];
			else{
				tri[i][j] = min(tri[i-1][j], tri[i-1][j-1]) + tri[i][j];
			}
		}
	}
	int m = tri[n-1][0];
	int index = 0;
	for(int i = 1; i < tri[n-1].size(); i++)
		if(m > tri[n-1][i]){
			m = tri[n-1][i];
			index = i;
		}
	int i = n-1;
	int r = m;
	vector<int> res;
	while(i >= 0){
		if(i == 0)
			break;
		if(index == 0){
			res.push_back(tri[i][index] - tri[i-1][index]);
		}
		else if(index == tri[i].size() - 1){
			res.push_back(tri[i][index] - tri[i-1][--index]);
		}
		else{
			if(tri[i-1][index] > tri[i-1][index-1])
				res.push_back(tri[i][index] - tri[i-1][--index]);
			else
				res.push_back(tri[i][index] - tri[i-1][index]);
		}
		i-=1;
	}
	res.push_back(tri[0][0]);
	reverse(res.begin(), res.end());
	cout << "Min sum path: ";
	for(auto &e: res)
		cout << e << " ";
	cout << endl;
	return r;
}

int main(){
	vector<vector<int>> vec = {{2}, {3, 7}, {8,5,6}, {6,1,9,3}};
	cout << "Min sum: " << dynamic(vec) << endl;
	return 0;
}