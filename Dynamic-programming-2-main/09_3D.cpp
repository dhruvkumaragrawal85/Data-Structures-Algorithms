#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    int n=grid.size();
    int m=grid[0].size();
    if(j1<0 || j2<0 || j1>=m || j2>=m)return -(1e9);
    if(i==n-1)
    {
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    vector<int> moves={-1, 0, 1};
    int maxi=0;
    for(auto m1: moves)
    {
        for(auto m2: moves)
        {
            int x1=j1+m1, x2=j2+m2;
            if(j1==j2)
            maxi=grid[i][j1]+solve(i+1, x1, x2, grid, dp);
            maxi=max(maxi, grid[i][j1]+grid[i][j2]+solve(i+1, x1, x2, grid, dp));
        }
    }
    return maxi;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>grid(n, vector<int>(m, 0));
    vector<vector<int>>dp(n, vector<int>(m, -1));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<solve(0, 0, m-1, grid, dp);
}