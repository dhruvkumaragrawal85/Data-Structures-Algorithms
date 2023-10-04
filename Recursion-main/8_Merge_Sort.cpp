#include <bits/stdc++.h>
using namespace std;
void mergefunc(vector<int> &v, int l, int mid, int r)
{
    int lsize=mid-l+1;
    int rsize=r-(mid+1)+1;
    vector<int> larr(lsize+1, 0);
    vector<int> rarr(rsize+1, 0);
    larr[lsize]=INT_MAX;
    rarr[rsize]=INT_MAX;
    for(int i=0; i<lsize; i++)
    {
        larr[i]=v[l+i];
        // cout<<larr[i]<<endl;
    }
    for(int i=0; i<rsize; i++)
    {
        rarr[i]=v[mid+1+i];
        // cout<<rarr[i]<<endl;
    }
    //     for(auto x: larr)
    // cout<<x<<" ";
    // cout<<endl;

    //     for(auto x: rarr)
    // cout<<x<<" ";
    // cout<<endl;
    int x=0; int y=0, i=0;
    for(int i=l; i<=r; i++)
    {
        if(larr[x]<=rarr[y])
        {
            v[i]=larr[x];
            x++;
        }
        else
        {
            v[i]=rarr[y];
            y++;
        }
    }
}
void mergesort(vector<int> &arr, int l, int r)
{
    if(l>=r)
    return;
    int mid=(r+l)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    mergefunc(arr, l, mid, r);
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    mergesort(arr, 0, n-1);
    for(auto x: arr)
    cout<<x<<" ";
    cout<<endl;
}