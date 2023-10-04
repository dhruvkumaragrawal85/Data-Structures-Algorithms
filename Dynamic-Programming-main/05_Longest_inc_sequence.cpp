#include<bits/stdc++.h>
using namespace std;
int dp[2502];
/*

Check for all elements,
   All the elements lying left of it that are smaller and get the maximum steps to get there using recursion.

No explicity base case required.

*/
    int solve(int i, vector<int> &nums)
    {
        if(dp[i]!=-1)return dp[i];
        int temp=1;
        for(int j=0; j<i; j++)
        {
            if(nums[j]<nums[i])
            temp=max(temp, solve(j, nums)+1);
        }
        return dp[i]=temp;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int result=0;
        for(int i=0; i<nums.size(); i++)
        result=max(result, solve(i, nums));
        return result;
    }
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
    cin>>arr[i];
    cout<<lengthOfLIS(arr)<<endl;
}