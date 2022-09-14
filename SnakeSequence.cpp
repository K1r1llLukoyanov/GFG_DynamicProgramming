#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define M 4
#define N 4

struct Point{
	int x, y;
};

list<Point> findPath(int grid[N][M], int mat[N][M], int i, int j){
	list<Point> path;
	Point pt = {i, j};
	path.push_front(pt);
	while(grid[i][j] != 0){
		if(i > 0 && grid[i-1][j] + 1 == grid[i][j]){
			pt = {i-1,j};
			path.push_front(pt);
			i--;
		}
		else if(j > 0 && grid[i][j] - 1 == grid[i][j-1]){
			pt = {i, j-1};
			path.push_front(pt);
			j--;
		}
	}
	return path;
}

void dynamic(int mat[N][M]){
	int lookup[N][M];
	memset(lookup, 0, sizeof lookup);

	int max_row = 0;
    int max_col = 0;
	int max_len = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(i > 0 && abs(mat[i-1][j] - mat[i][j]) == 1)
				lookup[i][j] = max(lookup[i][j], lookup[i-1][j] + 1);
				if(max_len < lookup[i][j]){
					max_len = lookup[i][j];
					max_row = i, max_col = j;
				}
			if(j > 0 && abs(mat[i][j] - mat[i][j]) == 1){
				lookup[i][j] = max(lookup[i][j], lookup[i][j-1] + 1);
				if(max_len = lookup[i][j]){
					max_len = lookup[i][j];
					max_row = i, max_col = j;
				}
			}
		}
	}
	cout << "Maximum length of Snake sequence is: " << max_len << endl;
	list<Point> path = findPath(lookup, mat, max_row, max_col);

	cout << "Snake sequence: \n";
	for(auto it = path.begin(); it != path.end(); it++){
		cout << mat[it->x][it->y] << " (" << it->x << ", " << it->y << ")\n";
	}
}



int main(){
	int mat[M][N] =
    {
        {9, 6, 5, 2},
        {8, 7, 6, 5},
        {7, 3, 1, 6},
        {1, 1, 1, 7},
    };
	dynamic(mat);
	return 0;
}
