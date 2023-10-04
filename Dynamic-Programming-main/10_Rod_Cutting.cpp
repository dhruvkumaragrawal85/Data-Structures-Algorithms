#include <bits/stdc++.h>
using namespace std;

int dp[1002];
class Solution
{
public:
    int solve(int len, vector<int>&prices)
    {
        if(dp[len]!=-1)return dp[len];
        if(len==0)return 0;
        int result=0;
        for(int cut=1; cut<=prices.size(); cut++)
        {
            if(len-cut>=0)
            result=max(result, solve(len-cut, prices)+prices[cut-1]);
        }
        return dp[len]=result;
    }
    int cutRod(int price[], int n)
    {
        memset(dp, -1, sizeof(dp));
        vector<int> prices(price, price+n);
        return solve(n, prices);
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends