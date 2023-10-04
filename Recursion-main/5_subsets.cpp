#include <bits/stdc++.h>
using namespace std;
void subsets(vector<int> &v, int i, vector<int> &nums, vector<vector<int>> &ans)
{
    if(i==nums.size())
    {
        ans.push_back(v);
        return;
    }
    subsets(v, i+1, nums, ans);
    v.push_back(nums[i]);
    subsets(v, i+1, nums, ans);
    v.pop_back();
}
int main()
{
    int n;
    cin>>n;
    vector <vector<int>> ans;
    vector<int> v;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++)
    cin>>nums[i];
    subsets(v, 0, nums, ans);
    for(auto x: ans)
    {
        for(auto y: x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}