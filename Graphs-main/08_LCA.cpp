#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10000];
int parents[10000];
void dfs(int vertex, int parent=-1)
{
    parents[vertex]=parent;
    for(int child: graph[vertex])
    {
        if(child==parent)continue;
        dfs(child, vertex);
    }
}
vector<int> path(int x)
{
    vector<int> temp;
    while(x!=-1)
    {
        temp.push_back(x);
        x=parents[x];
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int v1, v2;
        cin>>v2>>v1;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    int x, y;
    cin>>x>>y;
    vector<int> path_x=path(x);
    vector<int> path_y=path(y);
    int len=INT_MAX;
    len=min(path_x.size(), path_y.size());
    int lca=0;
    for(int i=0; i<len; i++)
    {
        if(path_x[i]==path_y[i])
        lca=path_x[i];
        else
        break;    
    }
    // for(auto x: path_x)
    // cout<<x<<endl;
    // for(auto y: path_y)
    // cout<<y<<endl;
    cout<<lca<<endl;
}