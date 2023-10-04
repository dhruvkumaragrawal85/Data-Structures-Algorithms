#include <bits/stdc++.h>
using namespace std;
queue<int> q1, q2;
//double queue implementation
void pop1()
{
    if(q1.empty())
    {
        cout<<"Stack is empty.\n";
        return;
    }
    else
    q1.pop();
}
void push1()
{
    int x;
    cout<<"Enter value to push:";
    cin>>x;
    q2.push(x);
    while(!q1.empty())
    {
        int t=q1.front();
        q2.push(t);
        q1.pop();
    }
    queue<int> temp=q2;
    q2=q1;
    q1=temp;
}
void top1()
{
    if(q1.empty())
    {
        cout<<"Empty\n";
    }
    else
    cout<<"Top:"<<q1.front()<<endl;

}
void empty1()
{
    if(q1.empty())
    {
        cout<<"Empty\n";
    }
    else
    cout<<"Not empty\n";
}
int main()
{    
    while(1)
    {
    cout<<"1) pop\n2) push\n3) top \n4) empty\n";
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