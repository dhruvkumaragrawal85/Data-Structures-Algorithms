#include <bits/stdc++.h>
using namespace std;
int solve(int j, int i, vector<vector<int>> &dp, vector<vector<int>> &matrix)
{
    if(j==dp[0].size() || j<0)return INT_MIN;
    if(i==0)return matrix[i][j];
    int result=matrix[i][j];
    int one=solve(j, i-1, dp, matrix);
    int two=solve(j-1, i-1, dp, matrix);
    int three=solve(j+1, i-1, dp, matrix);
    cout<<i<<" "<<j<<" "<<one<<" "<<two<<" "<<three<<endl;
    result+=max(one, max(two, three));
    return result;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int maximal=INT_MIN;
    for(int j=0; j<m; j++)
    {
        int k=solve(j, n-1, dp, matrix);
        cout<<"etb"<<k<<endl;
        maximal=max(maximal, k);
    }
    return maximal;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
    
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int> (m, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<getMaxPathSum(grid)<<endl;
    }
}