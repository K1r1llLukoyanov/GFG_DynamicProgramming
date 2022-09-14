#include <bits/stdc++.h>
using namespace std;

int recur(int A, int B, vector<vector<int>> areas, int depth, int curr, map<pair<int, int>, int> &memo)
{
    if (A < 0 || B < 0)
        return depth - 1;

    pair<int, int> cur = make_pair(A, B);
    int val = 0;
    if (memo.find(cur) != memo.end())
        return memo[cur];
    else
    {
        switch (curr)
        {
        case 0:
            val = max(val, max(recur(A + areas[1][0], B + areas[1][1], areas, depth + 1, 1, memo), recur(A + areas[2][0], B + areas[2][1], areas, depth + 1, 2, memo)));
            break;
        case 1:
            val = max(val, max(recur(A + areas[0][0], B + areas[0][1], areas, depth + 1, 0, memo), recur(A + areas[2][0], B + areas[2][1], areas, depth + 1, 2, memo)));
            break;
        case 2:
            val = max(val, max(recur(A + areas[1][0], B + areas[1][1], areas, depth + 1, 1, memo), recur(A + areas[0][0], B + areas[0][1], areas, depth + 1, 0, memo)));
            break;
        default:
            return max(recur(A + areas[0][0], B + areas[0][1], areas, depth + 1, 0, memo),
                       max(recur(A + areas[1][0], B + areas[1][1], areas, depth + 1, 1, memo),
                           recur(A + areas[2][0], B + areas[2][1], areas, depth + 1, 2, memo)));
        }
    }
    memo[cur] = val;
    return val;
}

int main()
{
    int depth = 0;
    vector<vector<int>> areas = {{3, 2}, {-5, -10}, {-20, 5}};
    int A = 20;
    int B = 8;
    map<pair<int, int>, int> memo;
    cout << recur(A, B, areas, depth, -1, memo) << endl;
    return 0;
}
