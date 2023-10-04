#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int weight[N]={0};
int values[N]={0};
long long dp[1010][100100];
long long func(int index, int value)
{
    if(value==0)return 0;
    if(index<0)return 1e15;
    if(dp[index][value]!=-1)return dp[index][value];
    long long result=func(index-1, value);
    if(value-values[index]>=0)
    result=min(result, func(index-1, value-values[index])+weight[index]);
    return dp[index][value]=result;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin>>n>>w;
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
        cin>>values[i];
    }
    int maxval=1e5;
    for(int i=maxval; i>=0; i--)
    {
        if(func(n-1, i)<=w)
        {
            cout<<i<<endl;
            break;
        }
    }
}