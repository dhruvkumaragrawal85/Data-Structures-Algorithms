#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int multiples[N]={0};
int hp[N]={0};
vector<bool> isprime(N, 1);

int main()
{
    isprime[0]=isprime[1]=0;
    for(int i=1; i<N; i++)
    {
        if(isprime[i])
        {hp[i]=i;
            for(int j=2*i; j<N; j=j+i)
            {
                isprime[j]=0;
                hp[j]=i;
            }
        }
    }
    // for(int i=1; i<100; i++)
    // {
    //     cout<<i<<" "<<hp[i]<<endl;
    // }
    int n, q;
    cin>>n>>q;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        multiples[arr[i]]=1;
    }
    for(int i=2; i<N; i++)
    {
        if(multiples[i])
        {
            // cout<<i<<endl;
            for(long long int j=i; j<N; j=j*1LL*i)
            {
                if(j>N)break;
                multiples[j]=1;
            }
        }
    }
    while(q--)
    {
        int x;
        cin>>x;
        int hold=x;
        vector<int> v;
        while(hold>1)
        {
            int ft=hp[hold];
            while(hold%ft==0)
            {
                hold/=ft;
            }
            v.push_back(ft);
        }
        bool flag=false;
        // for(auto k:v)
        // cout<<k<<" "<<endl;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i; j<v.size(); j++)
            {
                int product=v[i]*v[j];
                if(i==j && x%product!=0)continue;
                int temp=x/product;
                if(multiples[temp] || temp==1)
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}