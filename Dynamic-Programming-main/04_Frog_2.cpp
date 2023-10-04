#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N];
int solve(int i, int k, vector<int> &v)
{
    int cost=INT_MAX;
    if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
    for(int j=1; j<=k; j++)
    {
        if(i-j>=0)
        {
            cost=min(cost, solve(i-j, k, v)+abs(v[i]-v[i-j]));
        }
    }
    return dp[i]=cost;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin>>n>>k;
    vector<int>v(n, 0);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<solve(n-1, k, v);
}