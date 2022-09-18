#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> grid, int i, int j, int r, int c){
    if(i > r || j > c)
        return 0;
    if(i == r && j == c)
        return 1;
    else if(grid[i][j] == 1)
        return 0;
    return recursion(grid, i+1, j, r, c) + recursion(grid, i, j+1, r, c);
}

int main(){
    vector<vector<int>> A = { { 0, 0, 0 },
                             { 0, 1, 0 },
                             { 0, 0, 0 } };
    int r = A.size(), c = A[0].size();
    cout << recursion(A, 0, 0, r-1, c-1) << endl;
    return 0;
}