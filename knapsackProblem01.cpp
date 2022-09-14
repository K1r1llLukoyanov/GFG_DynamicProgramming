#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int m = 8;
    int weights[4] = {2, 3, 4, 5};
    int points[4] = {1, 2, 5, 6};
    int dp[5][9];
    for(int i = 0; i < 9; i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i < 5; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i < 5; i++){
        for(int j = 1; j < 9; j++){
            if(j < weights[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]] + points[i-1]);
        }
    }

    cout << "Max points: " << dp[4][8] << endl;

    cout << "Included objects: ";

    int i = 4;
    int j = 8;

    while(true){
        if(dp[i][j] == 0)
            break;
        if(dp[i-1][j] == dp[i][j])
            i = i-1;
        else{
            cout << i << " ";
            i = i-1;
            j = j - weights[i];
        }
    }

    return 0;
}
