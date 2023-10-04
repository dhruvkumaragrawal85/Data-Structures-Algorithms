#include <bits/stdc++.h>
using namespace std;
const int N=1e9+7;
/*Binary exponentiation Iterative
Break the number in powers of two 

time=O(logb)

3^13=3^(1101);
         3^13=3^8 * 1
             +3^4 * 1
             +3^2 * 0
             +3^1 * 1;  
*/
int iterative_Exp(int a, int b)
{
    int ans=1;
    while(b)
    {
        if(b & 1)
        {
            ans=ans * a;
        }
        b=b >> 1;
        a = a * a;
    }
    return ans;
}
int main() {
	cout<<"Enter base num & power:";
    int a, b;
    cin>>a>>b;
    cout<<iterative_Exp(a, b);
}
