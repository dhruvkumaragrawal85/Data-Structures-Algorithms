#include <bits/stdc++.h>
using namespace std;

/*bitmask can be used to generate subsets.
Consider a set of elements [1,2,3]
The subsets can be considered as 

0-000-[]
1-001-[1]
2-010-[2]
3-011-[1 2]
4-100-[3]
5-101-[1 3]
6-110-[2 3]
7-111-[1 2 3]

 https://leetcode.com/problems/subsets/

*/

vector<vector<int>> subsets(vector<int>& nums) {
        int nsize=nums.size();
        int sub_size=(1<<nsize);
        vector<vector<int>> ans;
        for(int i=0; i<sub_size; i++)
        {
            vector<int> subset;
            for(int j=0; j<nsize; j++)
            {
                if((i & 1<<j)!=0)
                subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
}

int main()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    vector<vector<int>> subs=subsets(v);
    for(auto x: subs)
    {
        for(auto y: x)
        cout<<y<<" ";
        cout<<endl;
    }
}