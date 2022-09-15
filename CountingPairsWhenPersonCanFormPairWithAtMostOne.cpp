#include <bits/stdc++.h>
using namespace std;

int recursion(int n){
    if(n < 1)
        return 0;
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    
    return (n-1)*recursion(n-2) + recursion(n-1);
}

int dynamic(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= n; i++)
        dp[i] = (i-1)*dp[i-2] + dp[i-1];
    return dp[n];
}

int dynamicSpaceOptimized(int n){
    if(n < 0)
        return 0;
    else if(n == 1)
        return 1;
    int a = 1;
    int b = 2, t;
    for(int i = 3; i <= n; i++){
        t = b;
        b = (i-1)*a + b;
        a = t;
    }
    return b;
}

int main(){
    cout << recursion(6) << endl;
    cout << dynamic(6) << endl;
    cout << dynamicSpaceOptimized(6) << endl;
    /* 
        for 4: 10
        1)  [1, 2], 3, 4
        2)  1, [2, 3], 4
        3)  1, 2, [3, 4]
        4)  [1, 2], [3, 4]
        5)  [1, 3], 2, 4
        6)  [1, 4], 2, 3
        7)  [1, 3], [2, 4]
        8)  [1, 4], [2, 3]
        9)  1, 2, 3, 4
        10) [2, 4], 1, 3  
    */
    return 0;
}