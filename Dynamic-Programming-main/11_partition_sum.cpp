#include<bits/stdc++.h>
using namespace std;
int dp[20005][105];
    bool solve(vector<int>&nums, int a, int i)
    {

        if(a==0)return true;
        if(i<0)return false;
        if(dp[a][i]!=-1)return dp[a][i];
        bool temp=solve(nums, a,  i-1);
        if(a-nums[i]>=0)
        temp|=solve(nums, a-nums[i], i-1);
        return dp[a][i]=temp;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum=accumulate(nums.begin(), nums.end(), 0);
        // cout<<sum<<endl;
        if(sum%2==0)
        return solve(nums, sum/2, nums.size()-1);
        else
        return false;
    }

int main()
{
    
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<canPartition(arr)<<endl;
}