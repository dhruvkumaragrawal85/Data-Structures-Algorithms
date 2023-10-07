#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int N = 20;
vector<vector<double>> prob(N, vector<double>(N));
vector<double> dp(1 << 20, -1);
double calc(int mask, int fish, int n)
{
    int k = __builtin_popcount(mask);
    double choose = k * (k - 1) / 2;
    double lose = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (mask & 1 << i)
            lose += prob[i][fish];
    }
    return lose / choose;
}
double func(int mask, int n)
{
    if (__builtin_popcount(mask) == n)
        return 1.0;
    if (dp[mask] > -0.9)
        return dp[mask];
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(mask & 1 << i))
        {
            int prev_mask = mask ^ 1 << i;
            double prev_day = func(prev_mask, n);
            double dies = calc(prev_mask, i, n);
            ans += prev_day * dies;
        }
    }
    return dp[mask] = ans;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> prob[i][j];
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(10) << func(1 << i, n) << " ";
    }
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
