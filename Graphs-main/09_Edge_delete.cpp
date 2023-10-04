#include <bits/stdc++.h>
using namespace std;
void dfs(int vertex, int parent, vector<int>graph[], vector<int>& subtree, vector<int>& A)
{
    subtree[vertex]+=A[vertex-1];
    for(int child: graph[vertex])
    {
        if(child==parent)continue;
        dfs(child, vertex, graph, subtree, A);
        subtree[vertex]+=subtree[child];
    }
}
int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int N=A.size();
    vector<int> graph[N+1];
    vector<int> subtree(N+1, 0);
    for (auto x : B) {
        int u = x[0];
        int v = x[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // cout<<"vfs"<<endl;
    dfs(1, 0, graph, subtree, A);
    // cout<<"av"<<endl;
    long long ans=0;
    for(int i=2; i<=N; i++)
    {
        int part1=subtree[i];
        int part2=subtree[1]-part1;
        ans=max(ans, part1*1LL*part2);
    }
    for(auto x: subtree)
    cout<<x<<endl;
    // cout<<"j fk"<<endl;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> A; 
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        A.push_back(t);
    }
    vector<vector<int>> V(n-1);
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<2; j++)
        {
            int t;
            cin>>t;
            V[i].push_back(t);
        }
    }
    cout<<deleteEdge(A, V)<<endl;
}