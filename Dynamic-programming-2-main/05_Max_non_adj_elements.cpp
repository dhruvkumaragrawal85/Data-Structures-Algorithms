#include <bits/stdc++.h>
using namespace std;
int solve(int index, vector<int>& nums, vector<int>& dp)
{
    int ans=0;
    if(index==0)return nums[0];
    if(index<0)return 0;
    if(dp[index]!=-1)return dp[index];
    int l=nums[index]+solve(index-2, nums, dp);
    int r=solve(index-1, nums, dp);
    return dp[index]=max(l, r);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n, -1);
    int maxi=solve(n-1, nums, dp);
    return maxi;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<maximumNonAdjacentSum(arr)<<endl;
    }
    
}