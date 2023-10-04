#include <bits/stdc++.h>
using namespace std;
const int N = 501;
const int inf = 1e9;
int dist[N][N];
/*

I/P:     4
         5
         1 2 1
         1 4 3
         2 4 1
         2 3 6
         4 3 1

O/P:     0 1 3 2 
         I 0 2 1 
         I I 0 I 
         I I 1 0 
         
*/
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j)dist[i][j]=0;
            else
            dist[i][j] = 1e9;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        dist[v1][v2] = wt;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dist[i][k]!=inf && dist[k][j]!=inf)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dist[i][j]==inf)
                cout<<'I'<<' ';
                else
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
}