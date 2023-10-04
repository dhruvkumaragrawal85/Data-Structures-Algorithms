#include <bits/stdc++.h>
using namespace std;
int k;
/*

int f()
      if base_case
         return 1;
         else 
         return 0;
    ...
    ...
    l=f(..,..);
    ...
    ...
    r=f(..,..);
    ...
    return l+r

*/
int solve(int sum, int i, vector<int> &v)
{
    if(i==v.size())
    {
        if(sum==k)
        {
        return 1;
        }
        return 0;
    }
    int l=solve(sum, i+1, v);
    sum=sum+v[i];
    int r=solve(sum, i+1, v);
    sum=sum-v[i];
    return l+r;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++)
    cin>>v[i];
    cout<<"Enter k:";
    cin>>k;
    vector<int> temp;
    cout<<solve(0, 0, v);
}