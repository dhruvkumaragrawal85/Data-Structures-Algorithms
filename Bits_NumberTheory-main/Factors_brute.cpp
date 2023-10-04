#include <bits/stdc++.h>
using namespace std;
const long long M=1e9+7;
/*
Naive approach: Run loop from 1 to n and check for factors4.
Complexity: O(n)
Sligthly optimized approach: Run loop till root(n)
Complexity: O(sqrt(n))

Still not a quick enough approach.
*/
void factors(int x)
{
    int sum=0;
    int count=0;
    for(int i=1; i*i<=x; i++)
    {
        if(x % i==0)
        {
            if(x / i != i)
            {
                cout<<i<<" "<<x/i<<endl;
                sum+=i;
                sum+=x/i;
                count++;
                count++;
            }
            else
            {
                cout<<i<<endl;
                sum+=i;
                count++;
            }
        }
    }
    cout<<"SUM: "<<sum<<endl;
    cout<<"Count: "<<count<<endl;
}
int main() {
    cout<<"Enter number:";
    int n;
    cin>>n;
    factors(n);
}
