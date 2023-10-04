#include <bits/stdc++.h>
using namespace std;
int vis[1001][1001];
int level[1001][1001];
vector<pair<int, int>>moves={{1, 0},{0, 1},{-1, 0},{0, -1}};
bool valid(int x, int y, vector<vector<char>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    return (x>=0)&&(y>=0)&&(x<n)&&(y<m)&&((grid[x][y]>='0')&&(grid[x][y]<='9') || grid[x][y]=='S');
}
void bfs(int i, int j, vector<vector<char>>&grid)
{
    queue<pair<int, int>>q;
    q.push({i, j});
    vis[i][j]=1;
    while(!q.empty())
    {
        pair<int, int> cell=q.front();
        q.pop();
        int x=cell.first, y=cell.second;
        for(auto k:moves)
        {
            int childx=x+k.first;
            int childy=y+k.second;
            if(!valid(childx, childy, grid))continue;
            if(vis[childx][childy]==0)
            {
                vis[childx][childy]=1;
                q.push({childx, childy});
                level[childx][childy]=level[x][y]+1;
            }
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    int xi=0, yi=0;
    int xf=0, yf=0;
    vector<vector<char>>grid(n, vector<char>(m, '0'));
    vector<pair<int, pair<int, int>>>opp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='E')
            {xi=i; yi=j;}
            if(grid[i][j]=='S')
            {xf=i; yf=j;}
            if(grid[i][j]>='1' && grid[i][j]<='9')
            {
                opp.push_back({(grid[i][j]-'0'), {i, j}});
            }
        }
    }
    bfs(xi, yi, grid);
    int sum=0;
    int dist=level[xf][yf];
    for(auto x: opp)
    {
        if(level[x.second.first][x.second.second]<=dist && level[x.second.first][x.second.second]!=0)
        sum+=x.first;
    }
    cout<<sum<<endl;
}