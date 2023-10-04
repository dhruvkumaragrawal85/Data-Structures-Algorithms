#include<bits/stdc++.h>
using namespace std;
const int N=1e3+15;
vector<int> graph[N];
vector<int> height(N, 0);
vector<int> depth(N,0);
void dfs(int vertex, int parent=0)
{
    for(int child:graph[vertex])
    {
        if(child==parent)continue;
        depth[child]=depth[vertex]+1;
        dfs(child, vertex);
        height[vertex]=max(height[vertex], height[child]+1);
    }
}
/*

I/P:
6
1 2
1 3
2 4
2 5
5 6
O/P:
1: 3 0
2: 2 1
3: 0 1
4: 0 2
5: 1 2
6: 0 3

*/
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
    for(int i=1; i<=n; i++)
    {
        cout<<i<<": "<<height[i]<<" "<<depth[i]<<endl;
    }
}