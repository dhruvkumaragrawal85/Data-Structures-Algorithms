#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
bool visited[N];
vector<int> graph[N];
bool connected=false;
bool dfs(int vertex, int parent)
{
    bool temp=false;
    visited[vertex]=true;
    for(int child:graph[vertex])
    {
        if(visited[child] && child==parent)continue;
        if(visited[child])return true;
        temp|=dfs(child, vertex);
    }
    return temp;
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
            if(dfs(i, 0))
            {
                connected=true;
                break;
            }
        }
    }
    if(connected)
    cout<<"There is a cycle\n";
    else
    cout<<"There is no cycle\n";
}