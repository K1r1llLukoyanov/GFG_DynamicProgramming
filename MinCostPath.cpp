#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 5

void dynamic(int cost[R][C]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(i == 0 && j == 0)
                continue;
            
            if(i == 0)
                cost[i][j] += cost[i][j-1];
            else if(j == 0)
                cost[i][j] += cost[i-1][j];
            else
                cost[i][j] += min(cost[i-1][j], min(cost[i][j-1], cost[i-1][j-1]));
        }
    }
    vector<int> path;
    int i = R-1, j = C-1;
    while(true){
        if(i == 0 && j == 0){
            path.push_back(cost[i][j]);
            break;
        }

        if(i == 0)
            path.push_back(cost[i][j] - cost[i][--j]);
        else if(j == 0)
            path.push_back(cost[i][j] - cost[--i][j]);
        else{
            if(cost[i-1][j] < cost[i][j-1] && cost[i-1][j] < cost[i-1][j-1])
                path.push_back(cost[i][j] - cost[--i][j]);
            else if(cost[i][j-1] < cost[i-1][j] && cost[i][j-1] < cost[i-1][j-1])
                path.push_back(cost[i][j] - cost[i][--j]);
            else
                path.push_back(cost[i][j] - cost[--i][--j]);
        }
    }

    reverse(path.begin(), path.end());
    cout << "Min sum path: ";
    for(auto &e: path)
        cout << e << " ";
    cout << endl;    
}

int main(){
    int cost[R][C] = { {1, 8, 8, 1, 5},
                      {4, 1, 1, 8, 1},
                      {4, 2, 8, 8, 1},
                      {1, 5, 8, 8, 1} };
    dynamic(cost);
    return 0;
}