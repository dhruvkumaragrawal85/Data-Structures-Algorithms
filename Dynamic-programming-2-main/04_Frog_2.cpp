#include <bits/stdc++.h>
using namespace std;
int solve(int index, int k, vector<int>&heights, vector<int>&dp)
{
  int ans=INT_MAX;
  if(index==0)return 0;
  if(dp[index]!=-1)return dp[index];
  for(int i=k; i>0; i--)
  {
    if(index-i>=0)
    ans=min(ans, solve(index-i, k, heights, dp)+abs(heights[index]-heights[index-i]));
  }
  return dp[index]=ans;
}
  
int main()
{
  int n, k;
  cin>>n>>k;
  vector<int> heights(n);
  vector<int> dp(n, -1);
  for(int i=0; i<n; i++)
    cin>>heights[i];
  cout<<solve(n-1, k, heights, dp);
}