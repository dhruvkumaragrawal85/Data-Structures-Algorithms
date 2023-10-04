#include <bits/stdc++.h>
using namespace std;
const int N=1e5+8;
const int inf=1e9;
vector<pair<int, int>> graph[N];
vector<int> level(N, inf);
void bfs()
{
    deque<int> q;
    q.push_back(1);
    level[1]=0;
    while (!q.empty())
    {
        int element=q.front();
        q.pop_front();
        for(auto child: graph[element])
        {
            int vertex=child.first;
            int wt=child.second;
            if(level[element]+wt<level[vertex])
            {
                level[vertex]=level[element]+wt;
                if(wt==1)
                q.push_back(vertex);
                else
                q.push_front(vertex);
                // cout<<element<<" "<<vertex<<" "<<level[7]<<endl;
            }
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        if(v1==v2)continue;
        graph[v1].push_back({v2, 0});
        graph[v2].push_back({v1, 1});
    }
    bfs();
    // for(int i=1; i<=n; i++)
    // cout<<level[i]<<endl;
    if(level[n]==inf)
    cout<<-1<<endl;
    else
    cout<<level[n]<<endl;
}