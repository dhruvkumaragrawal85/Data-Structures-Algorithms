#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector<int> parent(N);
vector<int> tsize(N);
set<int> St;
int hsh[N + 2];
int mindiff = INT_MAX;
int ans = 0;
void make(int v)
{
    parent[v] = v;
    tsize[v] = 1;
    hsh[1]++;
}
int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
int Union(int a, int b, int n)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        parent[a] = b;

        int sy = tsize[b];
        hsh[sy]--;
        if (hsh[sy] == 0)
            St.erase(sy);

        int sx = tsize[a];
        hsh[sx]--;
        if (hsh[sx] == 0)
            St.erase(sx);

        tsize[b] += tsize[a];
        sy = tsize[b];
        hsh[sy]++;
        if (hsh[sy] == 1)
            St.insert(sy);

        int pv = -1;
        int mn = n + 1;
        for (auto it = St.begin(); it != St.end(); it++)
        {
            int vl = (*it);
            if (hsh[vl] > 1)
            {
                mn = 0;
                break;
            }
            if (pv != -1)
            {
                mn = min(mn, vl - pv);
            }
            pv = vl;
        }
        if (mn == n + 1)
            mn = 0;
        ans = mn;
    }
    return ans;
}
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    St.insert(1);
    while (q--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        cout << Union(v1, v2, n)<<endl;
    }
}