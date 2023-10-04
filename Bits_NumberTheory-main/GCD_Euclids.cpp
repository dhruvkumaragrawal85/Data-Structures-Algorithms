#include <bits/stdc++.h>
using namespace std;

/*
Consider two numbers a,b
a * b = gcd(a,b) * lcm(a,b)

GCD can be calculated using the euclidean algorithm

Say we have numbers (12, 18), GCD calculation

   __
12|18|1
   12   __
     =6|12|2
        12
         =0

gcd(a, b)=gcd(b, a%b) until a%b!=0          
*/

int gcd_func(int a, int b)
{
    if(b==0)
    return a;
    return gcd_func(b, a%b);
}
int main()
{
    cout<<"Enter two numbers:\n";
    int a, b;
    cin>>a>>b;
    cout<<"GCD:"<<gcd_func(a, b)<<endl;
}