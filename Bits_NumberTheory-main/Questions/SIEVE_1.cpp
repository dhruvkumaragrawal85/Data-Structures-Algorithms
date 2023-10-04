#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int multiples[N]={0};
int hsh[N]={0};
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        hsh[n]++;
    }
    for(int i=1; i<N; i++)
    {
        for(int j=i; j<N; j=j+i)
        {
            multiples[i]+=hsh[j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        long long int c;
        c=(a*1LL*b)/__gcd(a, b);
        int ans=multiples[a]+multiples[b];
        if(c<N)
        ans-=multiples[c];
        cout<<ans<<endl;
    }
}