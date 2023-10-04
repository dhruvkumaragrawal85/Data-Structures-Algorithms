#include <bits/stdc++.h>
using namespace std;

//n<=1e3

const int N=1e3+10;
int graph1[N][N];

/*
    adjacency matrix
    ->faster in answering is there an edge between i & j, weight of the edge between i & j.
    
    ->Very high space complexity, O(N^2).


    adjacency list
    ->Low space complexity, O(V+E).

    ->Need to run an O(N) loop to answer the above questions.
*/

vector<pair<int, int>> graph2[N];
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int v1, v2, w;
        cin>>v1>>v2>>w;
        graph1[v1][v2]=w;
        graph1[v2][v1]=w;
        graph2[v1].push_back({v2, w});
        graph2[v2].push_back({v1, w});
    }
}
