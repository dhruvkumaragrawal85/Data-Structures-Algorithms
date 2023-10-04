#include <bits/stdc++.h>
using namespace std;
int dp[10010];
/*

Try every element and recurse for every element again & again.

*/
int solve(vector<int> &coins, int amount)
{
    if(amount==0)return 0;
    if(dp[amount]!=-1)return dp[amount];
    int result=INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        if(amount-coins[i]>=0)
        result=min(result+0LL, solve(coins, amount-coins[i])+1LL);
    }
    return dp[amount]=result;
}
int coinChange(vector<int>& coins, int amount) {
    int ans=solve(coins, amount);
    if(ans==INT_MAX)
    ans=-1;
    return ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, amount;
    cin>>n>>amount;
    vector<int>coins;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        coins.push_back(t);
    }    
    cout<<coinChange(coins, amount)<<endl;
}