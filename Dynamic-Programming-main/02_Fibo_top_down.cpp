#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N];
/*
steps
-write the brute recursion
-create an array to store the results, of the size=number of states of the dp
-assign a value to all the array elements which is not an answer to any of the subproblems
-return the precomputed value from the array
*/
int solve(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;

    if(dp[n]!=-1)return dp[n];//memoization step

    return dp[n]=solve(n-1)+solve(n-2);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}