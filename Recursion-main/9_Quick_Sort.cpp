#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &arr, int low, int high)
{
    int pivot=arr[low];
    int l=low;
    int r=high;
    while ((l<r))
    {
        while(arr[l]<=pivot && l<high)
        {l++;}
        while (arr[r]>pivot && r>low)
        {r--;}
        if(l<r)
        swap(arr[l], arr[r]);
    }
    swap(arr[low], arr[r]);
    return r;
    
}
void solve(vector<int> &arr, int low, int high)
{
    if(low<high)
    {
        int position=func(arr, low, high);
        solve(arr, low, position-1);
        solve(arr, position+1, high);
    }
}
vector<int> quickSort(vector<int> arr)
{
    int n=arr.size();
    solve(arr, 0, n-1);
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
    cin>>arr[i];
    vector<int> ans=quickSort(arr);
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
}