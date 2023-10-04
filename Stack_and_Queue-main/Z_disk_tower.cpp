#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    priority_queue<int>q;
    int max=n;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        q.push(t);
        while(q.top()==max)
        {
            cout<<q.top()<<" ";
            q.pop();
            max--;
        }
        cout<<endl;
    }
}