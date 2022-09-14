#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int diff){
    if(abs(diff) > n)
        return 0;
    if(n == 1 && abs(diff) == 1)
        return 1;
    if(n == 1 && diff == 0)
        return 2;

    return recursion(n-1, diff+1) + 2*recursion(n-1, diff) + recursion(n-1, diff-1);
}

int dynamic(int n){
    int nCr=1, res = 1;

    // Calculate SUM ((nCr)^2)
    for (int r = 1; r<=n ; r++)
    {
        // Compute nCr using nC(r-1)
        // nCr/nC(r-1) = (n+1-r)/r;
        nCr = (nCr * (n+1-r))/r;

        res += nCr*nCr;
    }

    return res;
}


int main(){
    cout << dynamic(2) << endl;
    return 0;
}
