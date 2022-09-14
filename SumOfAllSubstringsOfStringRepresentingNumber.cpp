#include <bits/stdc++.h>
using namespace std;

int dynamic(string str)
{
    int n = str.length();
    int sumofdigits[n + 1];
    sumofdigits[0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sumofdigits[i] = sumofdigits[i - 1] * 10 + (i) * (str[i - 1] - '0');
        sum += sumofdigits[i];
    }
    /* 
        для str = "421":
        sumofdigits[0] = 0;
        sumofdigits[1] = 0*10 + 1*4 = 4
        sumofdigits[2] = 4*10 + 2*2 = 42 + 2
        sumofdigits[3] = (42 + 2)*10 + 3*1 = 421 + 21 + 1
        
        Итого: 4 + 42 + 2 + 421 + 21 + 1 = 1 + 2 + 4 + 42 + 21 + 421 = 491
    */
    return sum;
}

int main()
{
    string str = "1234";
    /*
        1234 -> 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670
    */
    cout << dynamic(str) << endl;
    return 0;
}