#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> graph[N];
bool visited[N];
void dfs(int vertex)
{
    /*
       Computation after entering the vertex
    */
    cout<<vertex<<endl;
    visited[vertex]=true;
    for(int child: graph[vertex])
    {
        cout<<"Parent: "<<vertex<<"\t"<<"Child: "<<child<<endl;
        if(visited[child])continue;
        /*
            Computation before entering the child
        */
        dfs(child);
        /*
            Computation after exiting the chile
        */
    }
    /*
       Computation before exiting a node
    */
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        graph[v2].push_back(v1);
        graph[v1].push_back(v2);
    }
    dfs(1);
}