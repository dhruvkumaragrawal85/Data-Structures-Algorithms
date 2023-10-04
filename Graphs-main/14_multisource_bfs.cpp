#include<bits/stdc++.h>
using namespace std;
const int N=501;
int grid[N][N];
int level[N][N];
int visited[N][N];
int n, m;
vector<pair<int, int>> moves={
    {1, 0},{-1, 0},{0, 1},{0,-1},
    {1, 1},{1, -1},{-1, 1},{-1,-1}
};
void reset()
{
    for(int i=0; i<501; i++)
    {
        for(int j=0; j<501; j++)
        {
            level[i][j]=1e9;
            visited[i][j]=0;
            grid[i][j]=0;
        }
    }
}
bool valid(int x, int y)
{
    return x>=0 && y>=0 && x<n && y<m;
}
int bfs()
{
    int maxi=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            maxi=max(maxi, grid[i][j]);
            // cout<<grid[i][j]<<endl;
        }
    }
    queue<pair<int, int>>q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]==maxi)
            {
                q.push({i, j});
                level[i][j]=0;
                visited[i][j]=1;
            }
        }
    }
    // cout<<maxi<<"sd"<<endl;
    int ans=0;
    while(!q.empty())
    {
        pair<int, int>cell=q.front();
        q.pop();
        for(auto move: moves)
        {
            int cx=cell.first+move.first;
            int cy=cell.second+move.second;
            if(!valid(cx, cy))continue;
            if(visited[cx][cy]==1)continue;
            visited[cx][cy]=1;
            level[cx][cy]=level[cell.first][cell.second]+1;
            q.push({cx, cy});
            ans=max(ans, level[cx][cy]);
            // cout<<cx<<" "<<cy<<" "<<level[cx][cy]<<endl;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        reset();
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
}