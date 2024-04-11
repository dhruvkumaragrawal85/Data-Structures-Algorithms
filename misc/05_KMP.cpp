class Solution
{
    public:
        vector<int> prefix_function(string s)
        {
            int n=s.size();
            vector<int> pi(n, 0);
            for(int i=1; i<n; i++)
            {
                int j=pi[i-1];
                while(j>0 && s[i]!=s[j])
                j=pi[j-1];
                if(s[i]==s[j])
                j++;
                pi[i]=j;
            }
            return pi;
        }
        vector <int> search(string pat, string txt)
        {
            int n=pat.size();
            int m=txt.size();
            vector<int> pos;
            string concat=pat+"#"+txt;
            vector<int> pi=prefix_function(concat);
            for(int i=n+1; i<=n+m; i++)
            {
                if(pi[i]==n)
                pos.push_back(i-2*n+1);
            }
            return pos;
        }
     
};
