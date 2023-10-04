#include <bits/stdc++.h>
using namespace std;
int arr[6]={0};
int front=0;
int back=0;
int count1=0;
void pop1()
{
    if(count1==0)
    cout<<"Queue is empty\n";
    else
    {arr[front%6]=-1;
        front++;
    count1--;}
}
void push1()
{
    if(count1==6)
    cout<<"Memory overflow\n";
    else
    {
        cout<<"Element to push:";
        int x;cin>>x;
        arr[back%6]=x;
        back++;
        count1++;
    }
}
void top1()
{
    if(count1==0)
    cout<<"Queue is empty.\n";
    else
    cout<<arr[front%6]<<endl;
}
void empty1()
{
    // cout<<count1<<endl;
    if(count1){
        cout<<"NOT empty\n";
    }
    else
    cout<<"Empty.\n";
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