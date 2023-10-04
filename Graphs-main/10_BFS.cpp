#include <bits/stdc++.h>
using namespace std;
const int N=1e5+4;
vector<int> graph[N];
vector<int> vis(N, 0);
vector<int> level(N, 0);
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int element=q.front();
        q.pop();
        for(int child: graph[element])
        {
            if(vis[child]==0)
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[element]+1;
            }
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
}