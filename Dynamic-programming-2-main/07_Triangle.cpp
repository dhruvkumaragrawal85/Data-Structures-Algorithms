#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>&dp)      
{
	if(i==n-1)return triangle[n-1][j];
	if(dp[i][j]!=-1)return dp[i][j];
	int down=solve(i+1, j, triangle, n, dp);
	int diag=solve(i+1, j+1, triangle, n, dp);
	return dp[i][j]=(triangle[i][j]+min(down, diag));
} 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve(0, 0, triangle, n, dp);
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> tri(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cin>>tri[i][j];
        }
    }
    cout<<minimumPathSum(tri, n);
}