#include <bits/stdc++.h> 
using namespace std;
const int N=1e9+7;
long long solve(int index, vector<int>& heights, vector<long long>& dp)
{
    if(index<=0)return 0;
    if(dp[index]!=-1)return dp[index];
    long long ans=(solve(index-1, heights, dp)+abs(heights[index]-heights[index-1]))%N;
    if(index-2>=0)
    ans=(min(ans, solve(index-2, heights, dp)+abs(heights[index]-heights[index-2])))%N;
    return dp[index]=ans;
}
int frogJump(int n, vector<int> &heights)
{
    vector<long long>dp(n, -1);
    return solve(n-1, heights, dp)%N;
    /*
    Tabulation solution:

    vector<int> dp(n, 0)

    dp[0]=0;
    for(int i=1; i<n; i++)
    {
        int a=dp[i-1]+abs(heights[i]-heights[i-1]);
        int b=INT_MAX;
        if(i>1)
        b=dp[i-2]+abs(heights[i]-heights[i-2]);
    }

    return dp[n-1];

    This method reduces stack space used of O(N);
    Can further reduce space using something like prev, prev2;
    */
}
int main()
{
    int n;
    cin>>n;
    vector<int> heights(n, 0);
    for(int i=0; i<n; i++)
    {
        cin>>heights[i];
    }
    cout<<frogJump(n, heights);
}