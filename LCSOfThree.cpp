#include <bits/stdc++.h>
using namespace std;

int recursion(string a, string b, string c, int i, int j, int k, int n, int m, int r)
{
    if (i < n && j < m && k < r)
    {
        if (a[i] == b[j] && b[j] == c[k])
            return 1 + recursion(a, b, c, i + 1, j + 1, k + 1, n, m, r);
        else
        {
            int r1 = recursion(a, b, c, i + 1, j, k, n, m, r);
            r1 = max(r1, recursion(a, b, c, i, j + 1, k, n, m, r));
            r1 = max(r1, recursion(a, b, c, i, j, k + 1, n, m, r));
            return r1;
        }
    }
    return 0;
}

int dynamic(string a, string b, string c)
{
    int n = a.length(), m = b.length(), r = c.length();
    int dp[n + 1][m + 1][r + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= r; k++)
            {
                if (i == 0)
                {
                    dp[i][j][k] = 0;
                    continue;
                }
                else if (j == 0)
                {
                    dp[i][j][k] = 0;
                    continue;
                }
                else if (k == 0)
                {
                    dp[i][j][k] = 0;
                    continue;
                }

                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                {
                    int m = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                    m = max(m, dp[i][j][k - 1]);
                    dp[i][j][k] = m;
                }
            }
        }
    }
    int i = n;
    int j = m;
    int k = r;
    string res = "";
    while (dp[i][j][k] != 0)
    {
        if (dp[i][j][k] == dp[i - 1][j][k])
            i--;
        else if (dp[i][j][k] == dp[i][j - 1][k])
            j--;
        else if (dp[i][j][k] == dp[i][j][k - 1])
            k--;
        else
        {
            res += a[i - 1];
            i--;
            j--;
            k--;
        }
    }
    reverse(res.begin(), res.end());
    cout << "LCS: " << res << endl;
    return dp[n][m][r];
}

int main()
{
    string a = "geeks", b = "geeksfor", c = "geeksforgeeks";
    int n = a.length(), m = b.length(), r = c.length();
    cout << recursion(a, b, c, 0, 0, 0, n, m, r) << endl;
    cout << dynamic(a, b, c) << endl;
    return 0;
}