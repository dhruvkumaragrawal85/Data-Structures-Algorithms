#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> parent(N);
vector<int> size(N, 0);
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
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        make(i);
    }
    while(k--)
    {
        int v1, v2;
        cin>>v1>>v2;
        Union(v1, v2);
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(parent[i]==i)
        ans++;
    }
    cout<<ans<<endl;
}