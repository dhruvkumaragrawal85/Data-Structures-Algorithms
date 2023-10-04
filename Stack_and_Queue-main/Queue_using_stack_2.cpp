#include <bits/stdc++.h>
using namespace std;
stack<int> input, output;
void pop1()
{
    if(output.empty() && input.empty())
    cout<<"Queue is empty.\n";
    else
    {
        if(!output.empty())
        {
            output.pop();
        }
        else{
            while (!input.empty())
            {
                int t=input.top();
                output.push(t);
                input.pop();
            }
            output.pop();
        }
    }
}
void push1()
{
    cout<<"Element to push:";
    int x;cin>>x;
    input.push(x);
}
void top1()
{
    if(output.empty() && input.empty())
    cout<<"Queue is empty.\n";
    else
    {
        if(!output.empty())
        {
            cout<<"Front:"<<output.top()<<endl;
        }
        else{
            while (!input.empty())
            {
                int t=input.top();
                output.push(t);
                input.pop();
            }
            
            cout<<"Front:"<<output.top()<<endl;
        }
    }
}
void empty1()
{
    if(output.empty() && input.empty())
    cout<<"Queue is empty.\n";
    else
    {
        cout<<"Queue is not empty.\n";
    }
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