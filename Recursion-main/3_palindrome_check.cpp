#include <bits/stdc++.h>
using namespace std;
bool palin(string s, int i)
{
    int n=s.size();
    if(i>(n/2))
    return true;
    if(s[i]!=s[n-1-i])
    return false;
    return palin(s, i+1);
}
int main()
{
    string s;
    cin>>s;
    if(palin(s, 0))
    cout<<"Is a palindrome.\n";
    else
    cout<<"Is not a palindrome. \n";
}