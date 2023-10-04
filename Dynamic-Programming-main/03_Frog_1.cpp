#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N];
int solve(int i, vector<int> &v)
{
    int cost=INT_MAX;
    if(i==0) return 0;
    if(dp[i]!=-1)return dp[i];
    cost=min(cost, solve(i-1, v)+abs(v[i]-v[i-1]));
    if(i>1)
    cost=min(cost, solve(i-2, v)+abs(v[i]-v[i-2]));
    return dp[i]=cost;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        v[i]=t;
    }
    cout<<solve(n-1, v);
}