#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int, int>>graph[N];
vector<int> visited(N, 0);
vector<int> dist(N, 1e9);
void dijkstra(int source)
{
    dist[source]=0;
    set<pair<int, int>> store;
    store.insert({0, source});
    while(store.size()>0)
    {
        pair<int, int> node=*(store.begin());
        int v=node.second;
        int v_dist=node.first;
        store.erase(store.begin());
        if(visited[v]==1)continue;
        visited[v]=1;
        for(auto child: graph[v])
        {
            int child_node=child.first;
            int child_wt=child.second;
            if(dist[v]+child_wt<dist[child_node])
            {
                dist[child_node]=dist[v]+child_wt;
                store.insert({dist[child_node], child_node});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n>> m;
    for(int i=0; i<m; i++)
    {
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2, wt});
    }
    dijkstra(1);
    for(int i=1; i<n+1; i++)
    {
        cout<<i<<" :"<<dist[i]<<endl;
    }
}