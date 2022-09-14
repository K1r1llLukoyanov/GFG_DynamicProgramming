#include <bits/stdc++.h>
using namespace std;

#define N 4

bool recursion(int grid[N][N], int i, int j, int pi, int pj, int &sum){
    if(i >= N || j >= N)
        return true;
    if(grid[i][j] == 0){
        recursion(grid, i+1, j, i, j, sum);
        recursion(grid, i, j+1, i, j, sum);
        return false;
    }
    if(pi == i-1 && recursion(grid, i+1, j, i, j, sum)){
        if(recursion(grid, i, j+1, i, j, sum))
            sum += 1;
        return true;
    }
    else if(pi == i-1)
        return false;
    else if(pj == j - 1 && (recursion(grid, i, j+1, i, j, sum))){
        if(recursion(grid, i+1, j, i, j, sum))
            sum += 1;
        return true;
    }
    return false;
}
 
int dynamic(int grid[N][N]){
    int dp[N][N][2];
    dp[N-1][N-1][0] = grid[N-1][N-1];
    dp[N-1][N-1][1] = grid[N-1][N-1];
    int result = grid[N-1][N-1];
    for(int i = N-2; i >= 0; i--){
        dp[N-1][i][0] = grid[N-1][i];
        dp[N-1][i][1] = grid[N-1][i] && dp[N-1][i+1][1];
        dp[i][N-1][0] = grid[i][N-1] && dp[i+1][N-1][0]; 
        dp[i][N-1][1] = grid[i][N-1];
        result += (dp[N-1][i][1] + dp[i][N-1][0]);
    }
    for(int i = N-2; i >= 0; i--){
        for(int j = N-2; j >= 0; j--){
            dp[i][j][1] = dp[i][j+1][1] && grid[i][j];
            dp[i][j][0] = dp[i+1][j][0] && grid[i][j];
            if(dp[i][j][0] && dp[i][j][1])
                result += 1;
        }
    }
    return result;
}

int main(){
    int grid[N][N] = { {1, 0, 1, 1},
                         {0, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}};
    int sum = 0;
    recursion(grid, 0, 0, -1, -1, sum);
    cout << dynamic(grid) << endl;
    cout << sum << endl;
    return 0;
}