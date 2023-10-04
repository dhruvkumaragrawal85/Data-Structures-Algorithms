#include <bits/stdc++.h>
using namespace std;
int k;
void solve(int sum, int i, vector<int> &v, vector<int> &temp)
{
    if(i==v.size())
    {
        if(sum==k)
        {
        for(auto x: temp)
        cout<<x<<" ";
        cout<<endl;
        }
        return;
    }
    solve(sum, i+1, v, temp);
    sum=sum+v[i];
    temp.push_back(v[i]);
    solve(sum, i+1, v, temp);
    sum=sum-v[i];
    temp.pop_back();
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
    solve(0, 0, v, temp);
}