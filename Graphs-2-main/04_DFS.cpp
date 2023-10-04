#include <bits/stdc++.h>
using namespace std;

const int N=1e4;
vector<int> graph[N];
int vis[N];
int sumi[N];

void dfs(int node)
{
    vis[node]=1;
    for(auto child: graph[node])
    {
        if(vis[child])continue;
        sumi[child]=sumi[node]+child;
        dfs(child);
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
    sumi[1]=1;
    dfs(1);
    for(int i=1; i<=n; i++)
    {
        cout<<i<<": "<<sumi[i]<<endl; 
    }
}