#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int solve(int i, int j, string &s1, string &s2)
{
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=solve(i-1, j, s1, s2);
    ans=max(ans, solve(i, j-1, s1, s2));
    ans=max(ans, solve(i-1, j-1, s1, s2)+(s1[i]==s2[j]));
    return dp[i][j]=ans;
}
int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int x=text1.size();
        int y=text2.size();
        int ans=solve(x-1, y-1, text1, text2);
        return ans;
}
int main()
{
    string a, b;
    cin>>a>>b;
    cout<<longestCommonSubsequence(a, b)<<endl;
}