#include <bits/stdc++.h> 
using namespace std;         
int arr[6]={0};
int top=-1;
void pop1()
{
    if(top==-1)
    {
        cout<<"Stack is empty.\n";
        return;
    }
    top--;
}
void push1()
{
    if(top==5)
    {
        cout<<"Stack overflow\n";
        return;
    }
    int x;
    cout<<"Enter value to push:";
    cin>>x;
    top++;
    arr[top]=x;
}
void top1()
{
    if(top!=-1)
    cout<<"Top:"<<arr[top]<<endl;
    else
    cout<<"Stack is empty\n";
}
void empty1()
{
    if(top==-1)
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