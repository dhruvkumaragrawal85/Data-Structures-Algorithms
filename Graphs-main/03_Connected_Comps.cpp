#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
bool visited[N];
vector<int> graph[N];
vector<int> connected_comp;
void dfs(int vertex)
{
    visited[vertex]=true;
    connected_comp.push_back(vertex);
    for(int child:graph[vertex])
    {
        if(visited[child])continue;
        dfs(child);
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
    int count=0;
    vector<vector<int>> components;
    for(int i=1; i<=n; i++)
    {
        if(visited[i]==false)
        {
            count++;
            connected_comp.clear();
            dfs(i);
            components.push_back(connected_comp);
        }
    }
    cout<<count<<endl;
    for(auto x:components)
    {
        for(auto y: x)
        cout<<y<<" ";
        cout<<endl;
    }
}
