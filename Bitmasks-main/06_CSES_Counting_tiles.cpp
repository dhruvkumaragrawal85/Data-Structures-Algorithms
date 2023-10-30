#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
int n, m;
ll dp[1001][1 << 11];
void generate(int current_mask, int i, int next_mask, int n, vector<int> &next_masks)
{
    if (i == (n + 1))
    {
        next_masks.push_back(next_mask);
        return;
    }
    if ((current_mask & (1 << i)) != 0)
        generate(current_mask, i + 1, next_mask, n, next_masks);

    if (i != n)
        if ((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i + 1))) == 0)
            generate(current_mask, i + 2, next_mask, n, next_masks);

    if ((current_mask & (1 << i)) == 0)
        generate(current_mask, i + 1, next_mask + (1 << i), n, next_masks);
}
ll func(int i, int mask, int n, int m)
{
    if (i == (m + 1))
    {
        if (mask == 0)
            return 1;
        return 0;
    }
    if (dp[i][mask] != -1)
        return dp[i][mask];
    vector<int> next_masks;
    ll res = 0;
    generate(mask, 1, 0, n, next_masks);
    for (auto x : next_masks)
    {
        res = (res + func(i + 1, x, n, m)) % M;
    }
    return dp[i][mask] = res;
}
void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << func(1, 0, n, m);
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
