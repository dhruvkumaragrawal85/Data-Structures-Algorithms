#include <bits/stdc++.h>
using namespace std;
const int N=1e9+7;
long long solve(int nStairs, vector<long long>&dp) {
    long long ans=0;
    if(nStairs==0)
    return 1;
    if(dp[nStairs]!=-1)return dp[nStairs];
    if(nStairs-1>=0)
    ans+=solve(nStairs-1, dp)%N;
    if(nStairs-2>=0)
    ans+=solve(nStairs-2, dp)%N;
    return dp[nStairs]=((ans)%N);
}
int countDistinctWays(int nStairs) {
    vector<long long> dp(100005, -1);
    int ans=(solve(nStairs, dp))%N;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<countDistinctWays(n)<<endl;
}