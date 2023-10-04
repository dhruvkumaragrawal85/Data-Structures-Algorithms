#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
vector<int> parent(N), size(N);
void make(int v)
{
    parent[v]=v;
    size[v]=1;
}
int find(int v)
{
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(size[a]<size[b])
        swap(a, b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        make(i);
    }
    vector<pair<int, pair<int, int>>> graph;
    for(int i=0; i<m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        graph.push_back({wt, {u, v}});
    }
    int tree_sum=0;
    sort(graph.begin(), graph.end());
    for(int i=0; i<m; i++)
    {
        auto edge=graph[i];
        int wt=edge.first;
        int v1=edge.second.first;
        int v2=edge.second.second;
        if(find(v1)==find(v2))continue;
        else
        {
            Union(v1, v2);
            tree_sum+=wt;
            cout<<v1<<" "<<v2<<endl;
        }
    }
    cout<<tree_sum<<endl;
}