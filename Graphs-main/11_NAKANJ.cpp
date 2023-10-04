#include <bits/stdc++.h>
using namespace std;
int vis[8][8];
int level[8][8];
vector<pair<int, int>>movements={
    {1,2}, {-1, 2},
    {1,-2}, {-1, -2},
    {2,1}, {2,-1},
    {-2,1}, {-2,-1}
};
bool valid(int x, int y)
{
    return (x>=0)&&(y>=0)&&(x<8)&&(y<8);
}
int getx(string x)
{
    return x[0]-'a';
}
int gety(string x)
{
    return x[1]-'1';
}
void reset()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            vis[i][j]=0;
            level[i][j]=-1;
        }
    }
}
int bfs(string source, string dest)
{
    int xi=getx(source);
    int yi=gety(source);
    level[xi][yi]=0;
    int xf=getx(dest);
    int yf=gety(dest);
    // cout<<xi<<" "<<yi<<" "<<xf<<" "<<yf<<endl;
    queue<pair<int, int>> q;
    q.push({xi, yi});
    vis[xi][yi]=1;
    while(!q.empty())
    {
        pair<int, int> cell=q.front();
        q.pop();
        int tx=cell.first, ty=cell.second;
        for(auto j: movements)
        {
            int childx=tx+j.first;
            int childy=ty+j.second;
            // cout<<valid(childx, childy)<<endl;
            if(!valid(childx, childy))continue;
            if(vis[childx][childy]==0)
            {
                // cout<<"berg"<<endl;
                vis[childx][childy]=1;
                q.push({childx, childy});
                level[childx][childy]=level[tx][ty]+1;
                // cout<<level[childx][childy]<<endl;
            }
        }
        if(level[xf][yf]!=-1)break;
    }
    return level[xf][yf];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    reset();
    string a, b;
    cin>>a>>b;
    cout<<bfs(a, b)<<endl;
    }
}