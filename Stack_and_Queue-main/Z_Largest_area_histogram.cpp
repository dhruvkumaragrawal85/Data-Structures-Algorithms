//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
      long long getMaxArea(long long arr[], int n)
    {
        stack<long long> s;
        vector<long long>next_small(n, 0);
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[i]<arr[s.top()])
            {
                next_small[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
                next_small[s.top()]=-1;
                s.pop();
        }
        // for(auto x:next_small)
        // cout<<x<<" ";
        // cout<<endl;
        // for(int i=0; i<n; i++)
        // cout<<next_small[i]<<" ";
        // cout<<endl;
        vector<long long>prev_small(n, 0);
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && arr[i]<arr[s.top()])
            {
                prev_small[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
                prev_small[s.top()]=-1;
                s.pop();
        }
        long long area=0;
        for(int i=0; i<n; i++)
        {
            long long temp=0, l=0, r=0;
            if(next_small[i]==-1)
            r=n;
            else
            r=next_small[i];
            if(prev_small[i]==-1)
            l=0;
            else
            l=prev_small[i]+1;
            temp=(r-l)*arr[i];
            area=max(temp, area);
        }
        // for(auto x:prev_small)
        // cout<<x<<" ";
        // cout<<endl;
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends