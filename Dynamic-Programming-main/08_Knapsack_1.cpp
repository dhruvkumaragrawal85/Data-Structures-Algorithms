#include <bits/stdc++.h>
using namespace std;
long long dp[101][100001];
long long solve(vector<int>&arr1, vector<int>&arr2, int n, int w, int ind)
{
    long long ans=0;

    if(w==0)return 0;
    if(ind<0)return 0;
    if(dp[ind][w]!=-1)return dp[ind][w];
    ans=solve(arr1, arr2, n, w, ind-1);
    if(w-arr1[ind]>=0)
    ans=max(ans, 0LL+arr2[ind]+solve(arr1, arr2, n, w-arr1[ind], ind-1));
    return dp[ind][w]=ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin>>n>>w;
    vector<int> arr1, arr2;
    for(int i=0; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        arr1.push_back(x);
        arr2.push_back(y);
    }
    cout<<solve(arr1, arr2, n, w, n-1)<<endl;
}