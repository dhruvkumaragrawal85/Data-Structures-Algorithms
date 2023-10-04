#include <bits/stdc++.h>
using namespace std;
vector<string> sub_func(string s)
{
    int n=s.size();
    int n_subsets=1<<n;
    vector<string>ans;
    for(int i=0; i<n_subsets; i++)
    {
        string temp="";
        for(int j=0; j<n; j++)
        {
            if(i & 1<<j)
            {
                temp.push_back(s[j]);
            }
        }
        if(temp.size())
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // cout<<"hi\n";
        int n;
        cin>>n;
        unordered_map<string, int> hsh;
        string arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            set<char>hold;
            for(char ch:arr[i])
            {
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                {
                    hold.insert(ch);
                }
            }
            string temp="";
            for(auto x:hold)
            temp.push_back(x);
            vector<string> sbsets=sub_func(temp);
            for(auto x: sbsets)
            {
                hsh[x]++;
            }
        }
        // for(auto &x:hsh)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        long long int ans=0;
        for(auto &x:hsh)
        {
            if(x.second<3)continue;
            long long int y=((x.second) * 1LL * (x.second-1) * (x.second-2))/6;
            if(x.first.size()%2==0)
            {
                ans-=y;
            }
            else
            {
                ans+=y;
            }
        }
        cout<<ans<<endl;
    }
}