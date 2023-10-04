#include <bits/stdc++.h>
using namespace std;
/*Properties of XOR 
num XOR num = 0
num XOR  0  = num

Ques: In an array all numbers are present with an even count except one,
find out the one number using O(n) time and O(1) space. 

Logic:XORing all elements, each even number element will XOR another same element to zero,
we will be left with one number which does not have an matching pair.

XOR is associative in nature

To swap numbers a,b

a=a^b;
b=b^a;
a=a^b;
*/
void printbinary(int n)
{
    for (int i = 9; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
    return;
}
int main()
{
    cout<<'\t';
    printbinary(5);
    cout<<'\t';
    printbinary(5);
    cout<<"5^5  =  ";
    printbinary(5^5);
    cout<<'\t';
    printbinary(5);
    cout<<'\t';
    printbinary(0);
    cout<<"5^0  =  ";
    printbinary(5^0);
    vector<int> v={1,2,3,3,3,3,2,4,5,4,5,1,7,8,9,8,9};
    cout<<endl;
    for(auto x: v)
    cout<<x<<" ";
    cout<<endl;
    int ans=0;
    for(auto x: v)
    ans^=x;
    cout<<"Number with odd count: "<<ans<<endl<<endl;
    int a=11, b=9;
    cout<<"a="<<a<<" "<<"b="<<b<<endl;
    a=a^b;
    b=b^a;
    a=a^b;
    cout<<"After swap,\n";
    cout<<"a="<<a<<" "<<"b="<<b<<endl;
}