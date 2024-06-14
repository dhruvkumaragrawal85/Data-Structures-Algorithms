#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int tsize[N];

void make(int v)
{
    parent[v]=v;
    tsize[v]=1;
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
    if(tsize[a]<tsize[b])
    swap(a, b);
    parent[b]=a;
    tsize[a]+=tsize[b];
    }
}

int main()
{
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        make(i);
    }
    while(k--)
    {
        int u, v;
        cin>>u>>v;
        Union(u, v);
    }
    int connected_comp=0;
    for(int i=1; i<=n; i++)
    {
        if(parent[i]==i)
        connected_comp++;
    }
    cout<<"Connected comp are: "<<connected_comp<<endl;
}
