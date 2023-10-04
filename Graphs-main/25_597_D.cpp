#include <bits/stdc++.h>
using namespace std;
const int n=2e3;
vector<int> parent(n, 0);
vector<int> sz(n, 0);
void make(int v)
{
    parent[v]=v;
    sz[v]=1;
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
        if(sz[a]<sz[b])
        swap(a, b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        make(i);
    }
    vector<pair<int, int>>nodes(n+1);
    for(int i=1; i<=n; i++)
    {
        int x, y;
        cin>>x>>y;
        nodes[i]={x, y};
    }
    vector<int> c(n+1);
    vector<int> k(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>k[i];
    }
    vector<pair<long long, pair<int, int>>> edges;
    for(int i=1; i<=n; i++)
    {
        edges.push_back({c[i], {0, i}});
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            long long cost=abs(nodes[i].first-nodes[j].first)+abs(nodes[i].second-nodes[j].second);
            cost=cost*1LL*(k[i]+k[j]);
            edges.push_back({cost, {i, j}});
        }
    }
    int t=edges.size();
    sort(edges.begin(), edges.end());
    long long total=0;
    set<int> powerstations;
    set<pair<int, int>> con;
    for(int i=0; i<t; i++)
    {
        auto edge=edges[i];
        long long wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v))continue;
        if(u==0 || v==0)
        {
            powerstations.insert(max(u, v));
        }
        else
        {
            con.insert({u, v});
        }
        Union(u, v);
        total+=wt;
    }
    cout<<total<<endl;
    cout<<powerstations.size()<<endl;
    for(auto station: powerstations)
    cout<<station<<" ";
    cout<<endl;
    cout<<con.size()<<endl;
    for(auto line: con)
    cout<<line.first<<" "<<line.second<<endl;
}