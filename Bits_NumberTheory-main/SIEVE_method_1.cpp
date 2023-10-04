#include <bits/stdc++.h>
using namespace std;
const long long M=1e7+7;
vector<bool> v(M, 1);
/*

Sieve theorem, using unmarked numbers mark it multiples that lie ahead.

You will get Q queries with input number N, print if N is prime or not.

Q<=1e7
N<=1e7
*/
int main() {
    v[0]=v[1]=0;
    for(int i=2; i<M; i++)
    {
        if(v[i])
        {
            for(int j=2*i; j<M; j=j+i)
            {
                v[j]=0;
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        if(v[n])
        cout<<"Num is prime.\n";
        else
        cout<<"Num is not prime.\n";
    }
}
