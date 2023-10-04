//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        {
            stack<long long>s;
            vector<long long>index(n, 0);
            for(int i=0; i<n; i++)
            {
                while(!s.empty() && arr[i]>arr[s.top()])
                {
                    index[s.top()]=i;
                    s.pop();
                }
                s.push(i);
            }
            while(!s.empty())
            {
                index[s.top()]=-1;
                s.pop();
            }
            vector<long long>nge(n, 0);
            for(int i=0; i<n; i++)
            {
                if(index[i]==-1)
                nge[i]=-1;
                else
                nge[i]=arr[index[i]];
            }
            return nge;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
