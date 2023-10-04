#include <bits/stdc++.h>
using  namespace std;
int main()
{
    int n;
    cin>>n;
    int prev2=0;
    int prev1=1;
    long ans=0;
    if(n==0)ans=0;
    else if(n==1)ans=1;
    for(int i=2; i<=n; i++)
    {
        ans=prev1+prev2;
        prev2=prev1;
        prev1=ans;
    }
    cout<<ans<<endl;
}