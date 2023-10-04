#include <bits/stdc++.h>
using namespace std;
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	int b[num];
	queue<int> a;
	for(int i=0; i<num; i++)
	{
		int t;
		cin>>t;
		a.push(t);
	}
	for(int i=0; i<num; i++)
	{
		cin>>b[i];
	}
	int moves=0;
	int index=0;
	while(!a.empty())
	{
		if(a.front()==b[index])
		{
			a.pop();
			index++;
			moves++;
		}
		else
		{
			int k=a.front();
			a.pop();
			a.push(k);
			moves++;
		}
	}
	cout<<moves<<endl;
}