#include <bits/stdc++.h>
using namespace std;
/*
Consider all summations possible using an element and exclude that element for further calls.

Make a 2D dp array whose states are the index & the amount.
*/
int dp[310][5010];
int solve(int amount, vector<int>&coins, int i)
{
    if(amount==0)return 1;
    if(i<0)return 0;
    if(dp[i][amount]!=-1)return dp[i][amount];
    int ways=0;
    for(int coin_amt=0; coin_amt<=amount; coin_amt+=coins[i])
    {
        if(amount-coin_amt>=0)
        ways+=solve(amount-coin_amt, coins, i-1);
    }
    return dp[i][amount]=ways;
}
int change(int amount, vector<int>& coins) {
    memset(dp, -1, sizeof(dp));
    return solve(amount, coins, coins.size()-1);
}
int main()
{
    int n, amount;
    cin>>n>>amount;
    vector<int>coins;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        coins.push_back(t);
    }    
    cout<<change(amount, coins)<<endl;
}