#include <bits/stdc++.h>
using namespace std;
const int N=1e9+7;
/*Binary exponentiation
divide each power into two parts.

time=O(logb)

2^15=2 * 2^7 * 2^7;
         2^7=2 * 2^3 * 2^3;
                 2^3=2 * 2 * 2;  
*/
int recExp(int a, int b)
{
    if(b==0)
    return 1;
    int res=recExp(a, b/2);
    if(b & 1)
    return (a%N * (res * res)%N) % N;
    else
    return (res * res * 1LL) % N;
}
int main() {
	cout<<"Enter base num & power:";
    int a, b;
    cin>>a>>b;
    cout<<recExp(a, b);
}
