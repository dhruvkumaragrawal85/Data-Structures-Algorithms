#include <bits/stdc++.h>
using namespace std;
const long long M=1e5+7;
vector<bool> v(M, 1);
vector<int> lp(M, 0), hp(M,0);
vector<int> arr[M];
/*

Sieve theorem, using unmarked numbers mark it multiples that lie ahead.

You can store lowest and highest prime of a number.

To get factors repeatedly divide a number by its lp/hp and compute accordingly

Divisor variation of Sieve

*/
int main() {
    v[0]=v[1]=0;
    for(int i=2; i<M; i++)
    {
        if(v[i])
        {
            lp[i]=hp[i]=i;
            for(int j=2*i; j<M; j=j+i)
            {
                v[j]=0;
                hp[j]=i;
                if(lp[j]==0)
                {
                    lp[j]=i;
                }
            }
        }
    }
    for(int i=2; i<M; i++)
    {
            for(int j=2*i; j<M; j=j+i)
            {
                arr[j].push_back(i);
            }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int t=n;
        cout<<"Lowest prime:"<<lp[n]<<endl;
        cout<<"Highest prime:"<<hp[n]<<endl;
        map<int, int> mal;
        while(n>1)
        {
            int factor=hp[n];
            while(n%factor==0)
            {
                mal[factor]++;
                n/=factor;
            }
        }
        cout<<"Factors are:\n";
        for(auto x: mal)
        {
            cout<<"\t"<<x.first<<"->"<<x.second<<endl;
        }
        cout<<"Divisors are:\n";
        for(auto x: arr[t])
        {
            cout<<x<<endl;
        }
    }
}
