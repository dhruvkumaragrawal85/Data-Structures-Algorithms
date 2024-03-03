#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
/*   _  _       _     _ (n-1)  _ _
    | Fn |    |  1   1  |     | 1 |
    |    | =  |         |  •  |   |
    |Fn-1|    |  1   0  |     | 0 |
     ̅   ̅        ̅      ̅         ̅  ̅
     where F0=0,F1=1
*/
vector<vector<ll>> res = {{1}, {0}};
vector<vector<ll>> base_matrix = {{1, 1}, {1, 0}};
void mult(vector<vector<ll>> &final, vector<vector<ll>> m1, vector<vector<ll>> m2)
{
    vector<vector<ll>> temp = final;
    int r1 = m1.size();
    int c1 = m1[0].size();
    int r2 = m2.size();
    int c2 = m2[0].size();
    // matrix multiplication
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < r2; k++)
            {
                temp[i][j] = (temp[i][j] + (m1[i][k] * m2[k][j]) % M) % M;
            }
        }
    }
    final = temp;
}
void matrix_exp(ll n)
{
    while (n > 0)
    {
        if (n & 1)
        {
            mult(res, base_matrix, res);
        }
        mult(base_matrix, base_matrix, base_matrix);
        n = n >> 1;
    }
}
void solve()
{
    ll n;
    cin >> n;
    matrix_exp((n - 1));
    if (n == 0)
        cout << 0;
    else
        cout << res[0][0];
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
