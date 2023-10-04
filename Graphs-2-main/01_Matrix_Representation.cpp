#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int> (n+1, 0));
    for(int i=0; i<m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        graph[u][v]=wt;
        graph[v][u]=wt;
    }
    cout<<"# # ";
    for(int i=1; i<=n; i++)
    cout<<i<<" ";
    cout<<endl;
    for(int i=0; i<=n; i++)
    {
        if(i==0)
        cout<<"# ";
        else
        cout<<i<<" ";
        for(int j=0; j<=n; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}