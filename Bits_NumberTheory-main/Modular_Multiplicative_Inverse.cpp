#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
const int N=1e6+2;
int fact[N];
/*
Modular multiplicative inverse when m is prime:(A^(M-2))%M

Suppose: There are N children and K toffees, K<N. Count the number of ways
to distribute the toffees such that each student gets one toffee only-->nCk, %M 
N<1e6
K<N<1e6
Q<1e6
*/
int binexp(int a, int b, int m)
{
    int result=1;
    while(b>0)
    {
        if(b & 1)
        {
            result=(result * 1LL * a)%m;
        }
        a=(a * 1LL * a)%m;
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
    }
    int q;
    cin>>q;
    while(q--)
    {
        int n, k;
        cin>>n>>k;
        int ans=fact[n];
        int den=(fact[n-k] * 1LL * fact[k])%M;
        ans=(ans * 1LL * binexp(den, M-2, M))%M;
        cout<<ans<<endl;
    }
}
