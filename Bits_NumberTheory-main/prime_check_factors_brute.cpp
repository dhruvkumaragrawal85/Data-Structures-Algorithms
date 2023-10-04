#include <bits/stdc++.h>
using namespace std;
bool prime_check(int x)
{
    bool is_prime=true;
    if(x==1)
    return false;
    for(int i=2; i*i<=x; i++)
    {
        if(x % i==0)
        return false;
    }
    return true;
}
void factors(int n)
{
    vector<int> fact;
    for(int i=2; i*i<=n; i++)
    {
        while(n%i==0)
        {
            fact.push_back(i);
            n/=i;
        }
    }
    if(n>1)
    {
        fact.push_back(n);
    }
    for(auto x: fact)
    cout<<x<<endl;
}
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    if(prime_check(n))
    cout<<"PRIME NUMBER\n";
    else
    {cout<<"NOT A PRIME NUMBER\n";
    }
    factors(n);
}
