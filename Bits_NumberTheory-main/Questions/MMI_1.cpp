#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
const int N=1e5+7;
int fact[N];
/*

https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

*/
int binexp(int a, int b, int m)
{
    int result=1;
    while(b>0)
    {
        if(b&1)
        {
            result=(result * 1LL * a)%M;
        }
        a=(a * 1LL * a)%M;
        b=b>>1;
    }
    return result;
}
int main()
{
    fact[0]=fact[1]=1;
    for(int i=2; i<N; i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%M;
        // cout<<fact[i]<<endl;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int ans=(fact[k] * 1LL * binexp(fact[k-n], M-2, M))%M;
        cout<<ans<<endl;
    }
}