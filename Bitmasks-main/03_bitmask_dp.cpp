/*
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]
Sample Output
13

Constraints
N <= 20

Space complexity:O(n*(2^n))
Time complexity:O((n^2)*(2^n))

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
int func(int i, int mask, vector<vector<int>> &cost, int n, vector<vector<int>> &dp)
{
    if (mask == 0)
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int res = 1e9;
    for (int j = 0; j < n; j++)
    {
        if (mask & 1 << j)
            res = min(res, cost[j][i] + func(i + 1, mask & ~(1 << j), cost, n, dp));
    }
    return dp[i][mask] = res;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    int mask = (1 << n) - 1;
    vector<vector<int>> dp(n + 1, vector<int>(mask + 1, -1));
    cout << func(0, mask, cost, n, dp);
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
