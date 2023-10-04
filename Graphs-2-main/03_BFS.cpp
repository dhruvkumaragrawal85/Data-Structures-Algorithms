#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int vis[N];
vector<int> bfs_vec;
vector<int> graph[N];
void bfs(int source)
{
    queue<int> q;
    vis[source]=1;
    q.push(source);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        bfs_vec.push_back(t);
        for(auto x: graph[t])
        {
            if(vis[x])continue;
            vis[x]=1;
            q.push(x);
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    for(auto x: bfs_vec)
    {
        cout<<x<<" ";
    }
}