#include <bits/stdc++.h>
using namespace std;
int solve(int index, vector<int>& num, int target, vector<vector<int>>& dp)
{
    if(index==0)
    {
        if(target%num[0]==0)
        return target/num[0];
        else
        return 1e9;
    }
    if(dp[index][target]!=-1)return dp[index][target];
    int not_pick=solve(index-1, num, target, dp);
    int pick=1e9;
    if(target-num[index]>=0)
    pick=1+solve(index, num, target-num[index], dp);
    return dp[index][target]=min(not_pick, pick);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n, vector<int> (x+1, 0));
    int a=solve(n-1, num, x, dp);
    if(a==1e9)
    return -1;
    else
    return a;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    cin>>arr[i];
    int target;
    cin>>target;
    cout<<minimumElements(arr, target);
}