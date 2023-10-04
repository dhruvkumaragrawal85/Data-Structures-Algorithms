#include <bits/stdc++.h>
using namespace std;
void rev(vector<int> &v, int l, int r)
{
    if(l>r)
    return;
    swap(v[l], v[r]);
    return rev(v, l+1, r-1);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++)
    cin>>v[i];
    rev(v, 0, n-1);
    for(auto x: v)
    cout<<x<<" ";
}