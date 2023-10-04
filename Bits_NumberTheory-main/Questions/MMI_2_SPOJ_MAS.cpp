#include <bits/stdc++.h>
using namespace std;
const int M=100010;
const long long int mod = 2760727302517LL;

long long sum, sqsum;
long long arr[M];
/*
n=3;
F(A)=[
      (A[1]-A[1])^2 + (A[1]-A[2])^2 + (A[1]-A[3])^2 +
      (A[2]-A[2])^2 + (A[2]-A[3])^2 +
      (A[3]-A[3])^2 
     ]
     =2(A[1]^2 + A[2]^2 + A[3]^2)-2(A[1][2] + A[2][3] + A[3][1])


     a^2 + b^2 +c^2 = (a+b+c)^2 - 2(ab + bc + ca)

F(a)=3*(sum of sqrs) - (sum)^2
     n*(sum of sqrs) - (sum)^2    

*/
long long binmul(long long a, long long b)
{
    long long result=0;
    while(b>0)
    {
        if(b & 1)
        {
            result=(result+a)%mod;
        }
        b=b>>1;
        a=(a+a)%mod;
    }
    return result;
}
void add(int index, long long int value)
{
    value=value%mod;
    sum=(sum+mod-arr[index])%mod;
    sum=(sum+value)%mod;
    sqsum=(sqsum+mod-binmul(arr[index], arr[index]))%mod;
    sqsum=(sqsum+binmul(value, value))%mod;
    arr[index]=value;
}
int main()
{
    int t;
    cin>>t;
    int cases=1;
    while(cases<=t)
    {
        int n, q;
        cin>>n>>q;
        for(int i=1; i<=n; i++)
        cin>>arr[i];
        sum=0, sqsum=0;

        for(int i=1; i<=n; i++)
        {
            sum=(sum+arr[i])%mod;
            sqsum=(sqsum+arr[i]*arr[i])%mod;
        }

        cout<<"Case "<<cases<<":"<<endl;

        while(q--)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int x, v;
                cin>>x>>v;
                add(x, v);
            }
            else if(type==2)
            {
                int x, v;
                cin>>x>>v;
                add(x, arr[x]+v);
            }
            else
            {
                long long ans=(n*1LL*sqsum%mod-binmul(sum, sum) + mod)%mod;
                cout<<ans<<endl;
            }
        }
        cases++;
    }
}