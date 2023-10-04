#include <bits/stdc++.h>
using namespace std;
int sumfunc(vector<int> &arr, int i)
{
    if(i<0)
    return 0;
    return arr[i]+sumfunc(arr, i-1);
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
    cin>>arr[i];
    cout<<"Sum:"<<sumfunc(arr, n-1)<<endl;
}