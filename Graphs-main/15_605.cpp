#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n;
vector<int> a;
vector<int> ans;
vector<int> graph[N];
void bfs(vector<int> &start, vector<int>& end)
{
	vector<int> level(n, 1e9);
	queue<int> q;
	for(auto v: start)
	{
		level[v]=0;
		q.push(v);
	}
	while (!q.empty())
	{
		int v=q.front();
		q.pop();
		for(auto to:graph[v])
		{
			if(level[to]==1e9)
			{
				level[to]=level[v]+1;
				q.push(to);
			}
		}
	}
	for(auto v: end)
	{
		if(level[v]!=1e9)
		{
			ans[v]=level[v];
		}
	}
	
}
int main()
{
	cin>>n;
	vector<int>odd, even;
	for(int i=0; i<n; i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
		if(t&1)odd.push_back(i);
		else even.push_back(i);
	}
	for(int i=0; i<n; i++)
	{
		int lf=i-a[i];
		int rg=i+a[i];
		if(0<=lf)graph[lf].push_back(i);
		if(rg<n)graph[rg].push_back(i);
	}
	ans=vector<int>(n, -1);
	bfs(odd, even);
	bfs(even, odd);
	for(auto x: ans)
	cout<<x<<" ";
	cout<<endl;
	return 0;
}