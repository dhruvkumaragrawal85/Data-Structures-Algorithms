#include <bits/stdc++.h>
using namespace std;
stack<int> s1, s2;
void pop1()
{
    if(s1.empty())
    cout<<"Queue is empty.\n";
    else
    {
        s1.pop();
    }
}
void push1()
{
    while (!s1.empty())
    {
        int t=s1.top();
        s1.pop();
        s2.push(t);
    }
    cout<<"Element to push:";
    int x;cin>>x;
    s1.push(x);
    while (!s2.empty())
    {
        int t=s2.top();
        s2.pop();
        s1.push(t);
    }
}
void top1()
{
    if(s1.empty())
    cout<<"Queue is empty\n";
    else
    cout<<"Front:"<<s1.top()<<endl;
}
void empty1()
{
    if(s1.empty())
    cout<<"Queue is empty\n";
    else
    cout<<"Queue is not empty\n"<<endl;
}
int main()
{
while(1)
    {
    cout<<"1) pop\n2) push\n3) front \n4) empty\n";
    int choice=0;
    cin>>choice;
    switch (choice)
    {
    case 1:
    {
        pop1();
    }
        break;
    case 2:
    {
        push1();
    }
    break;
    case 3:
    {
        top1();
    }
    break;
    case 4:
    {
        empty1();
    }
    break;
    default:
    {
        return 0;
    }
        break;
    }
    }
}