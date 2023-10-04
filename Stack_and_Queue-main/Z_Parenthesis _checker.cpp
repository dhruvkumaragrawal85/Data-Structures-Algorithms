//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    unordered_map<char, int>m={{'(',-1},{'{',-2},{'[',-3},{')',1},{'}',2},{']',3}};
    bool ispar(string x)
    {
        stack<int> s;
        for(char ch: x)
        {
            if(m[ch]<0)
            {
                s.push(m[ch]);
            }
            else
            {
                if(s.empty()) return false;
                int t=s.top();
                if((t+m[ch])!=0) return false;
                s.pop();
            }
        }
        if(!s.empty())
        return false;
        else
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
