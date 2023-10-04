#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> parent(N);
vector<int> tsize(N);
multiset<int> gsize;
void make(int v)
{
    parent[v]=v;
    tsize[v]=1;
    gsize.insert(1);
}
int find(int v)
{
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
void merge(int a, int b)
{
    gsize.erase(gsize.find(tsize[a]));
    gsize.erase(gsize.find(tsize[b]));
    gsize.insert(tsize[a]+tsize[b]);
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
        merge(a, b);
        tsize[a]+=tsize[b];
    }
}
int main()
{
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        make(i);
    }
    while(q--)
    {
        int v1, v2;
        cin>>v1>>v2;
        Union(v1, v2);
        if(gsize.size()==1)
        cout<<0<<endl;
        else
        {
            int mini=*(gsize.begin());
            int maxi=*(--gsize.end());
            cout<<maxi-mini<<endl;
        }
    }
}