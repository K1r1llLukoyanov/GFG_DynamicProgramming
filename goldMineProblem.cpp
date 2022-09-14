#include <iostream>
using namespace std;

int goldMine(int mat[4][4], int n, int m, int i, int j){
    if(i >= n || i < 0)
        return 0;
    if(j >= m)
        return 0;
    return mat[i][j] + max(goldMine(mat, n, m, i+1, j+1), max(goldMine(mat, n, m, i, j+1), goldMine(mat, n, m, i-1, j+1)));
}

template<int N, int M>
int dynamic(int mat[N][M]){
    int dp[N][M];
    for(int i = 0; i < N; i++)
        dp[i][0] = mat[i][0];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < N; i++){
            dp[i][j] = mat[i][j] + dp[i][j-1];
            if(i != 0)
                dp[i][j] = max(dp[i][j], mat[i][j] + dp[i-1][j-1]);
            if(i != N-1)
                dp[i][j] = max(dp[i][j], mat[i][j] + dp[i+1][j-1]);
        }
    }
    int ma = 0;
    for(int i = 0; i < N; i++)
        ma = max(ma, dp[i][M-1]);
    return ma;
}

int main(){
    int mat[4][4] = { {1, 3, 1, 6},
                    {2, 2, 4, 1},
                    {5, 0, 2, 3},
                    {0, 6, 1, 2}};
    int sol = 0;
    for(int i = 0; i < 4; i++){
        sol = max(sol, goldMine(mat, 4, 4, i, 0));
    }
    int sol2 = dynamic<4, 4>(mat);
    cout << sol << endl;
    cout << sol2 << endl;
    return 0;
}
