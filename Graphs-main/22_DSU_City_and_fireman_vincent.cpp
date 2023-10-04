#include <bits/stdc++.h>
using namespace std;
const int N=1e3+4;
const int mod=1e9+7;
vector<int> parent(N);
vector<int> tsize(N);
vector<int> cost(N);
vector<int> penalty(N, 0);
void make(int v)
{
    parent[v]=v;
    tsize[v]=1;
    penalty[v]=1;
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
        if(cost[a]>cost[b])
        {cost[a]=cost[b];
        penalty[a]=penalty[b];}
        else if(cost[a]==cost[b])
        penalty[a]+=penalty[b];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        make(i);
        int t;
        cin>>t;
        cost[i]=t;
    }
    int k;
    cin>>k;
    while(k--)
    {
        int v1, v2;
        cin>>v1>>v2;
        Union(v1, v2);
    }
    int ans=1;
    for(int i=1; i<=n; i++)
    {
        if(parent[i]==i)
        ans=((ans%(mod))*penalty[i])%mod;
    }
    cout<<ans<<endl;
}