#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<long long> remove(n);
    vector<long long> sum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> remove[i];
    }
    reverse(remove.begin(), remove.end());
    for (int k = 0; k < n; k++)
    {
        long long deleted = remove[k];
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][deleted] + 0LL + arr[deleted][j]);
            }
        }
        long long temp=0;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                temp+=arr[remove[i]][remove[j]];
            }
        }
        sum.push_back(temp);
    }
    reverse(sum.begin(), sum.end());
    for(int i=0; i<n; i++)
    cout<<sum[i]<<" ";
}