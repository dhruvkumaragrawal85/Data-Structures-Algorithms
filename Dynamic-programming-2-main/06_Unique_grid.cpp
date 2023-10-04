#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>>&dp)
{
	if(i<0 || j<0)return 0;
	if(i==0 && j==0)return 1;
	if(dp[i][j]!=0)return dp[i][j];
	int l=solve(i-1, j, dp);
	int r=solve(i, j-1, dp);
	return dp[i][j]=l+r;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 0));
	int ans=solve(m-1, n-1, dp);
	return ans;
	// dp[0][0]=1;
	// for(int i=0; i<m; i++)
	// {
	// 	for(int j=0; j<n; j++)
	// 	{
	// 		if(i==0 && j==0)continue;
	// 		int l=0, r=0;
	// 		if(i-1>=0)
	// 		l=dp[i-1][j];
	// 		if(j-1>=0)
	// 		r=dp[i][j-1];
	// 		dp[i][j]=l+r;
	// 	}
	// }
	// return dp[m-1][n-1];
}
int main()
{
    int m, n;
    cin>>m>>n;
    cout<<uniquePaths(m, n)<<endl;
}