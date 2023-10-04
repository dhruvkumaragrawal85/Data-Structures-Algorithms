#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c;
    cin>>c;
    int a=0, b=0;
    int n=(int)log2(c)+1;
    vector<int> pos;
    for(int i=0; i<n; i++)
    {
        if(c & 1<<i)
        {
            pos.push_back(i);
        }
        else
        {
            a = a | 1<<i;
            b = b | 1<<i;
        }
    }
    int t=pos.size();
    int subsets=1<<t;
    long long ans=-1;
    for(int i=0; i<subsets; i++)
    {
        int atemp=a, btemp=b;
        for(int j=0; j<t; j++)
        {
            if(i & 1<<j)
            {
                atemp|=1<<pos[j];
            }
            else
            {
                btemp|=1<<pos[j];
            }
        }
        ans=max(ans, atemp * 1LL * btemp);
    }
    cout<<ans<<endl;
}