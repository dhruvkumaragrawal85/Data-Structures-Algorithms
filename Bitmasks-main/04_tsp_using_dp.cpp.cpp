#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int n = 4;
int dist[n][n] = {
    {0, 10, 15, 20},
    {10, 0, 25, 25},
    {15, 25, 0, 30},
    {20, 25, 30, 0}};
int func(int i, int mask, vector<vector<int>> &dp)
{
    // after completion cost of returning to starting point
    if (mask == 0)
        return dist[i][0];
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int res = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (1 << j & mask)
            res = min(res, func(j, mask & ~(1 << j), dp) + dist[i][j]);
    }
    return dp[i][mask] = res;
}
void solve()
{
    // create mask such that 1 is unassignable
    vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1));
    cout << func(0, (1 << n) - 2, dp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
