#include <bits/stdc++.h>
using namespace std;
const long long int M=1e18+7;
/*
If in Binary exponentiation, a is too large just take mod formost in the function.

If in Binary exponentiation, M is too large say 1e18 range, then after mod 
a/ans may be of that order as well, on next multiplication they will overflow.

To overcome this we use binary multiplication. Which breaks the multiplication into two parts
by breaking the second number into its binary representation. Similar to Binary exponention iterative method.

Time=O((logN)^2)
*/
long long int binMul(long long int a, long long int b);
long long int iterative_Exp(long long int a, long long int b)
{
    long long int ans=1;
    while(b)
    {
        if(b & 1)
        {
            ans=binMul(ans, a);
        }
        b=b >> 1;
        a = binMul(a, a);
    }
    return ans;
}
long long int binMul(long long int a, long long int b)
{
    long long int ans=0;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans + a)%M;
        }
        b=b>>1;
        a=(a + a)%M;
    }
    return ans;
}
int main() {
	cout<<"Enter base num & power:";
    int a, b;
    cin>>a>>b;
    cout<<iterative_Exp(a, b);
}
