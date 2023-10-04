#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> graph[N];
int psum[N];
void dfs(int vertex, int parent=0)
{
    psum[vertex]+=vertex;
    for(int child:graph[vertex])
    {
        if(child==parent)continue;
        dfs(child, vertex);
        psum[vertex]+=psum[child];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    for(int i=1; i<n+1; i++)
    {
        cout<<psum[i]<<endl;
    }
}