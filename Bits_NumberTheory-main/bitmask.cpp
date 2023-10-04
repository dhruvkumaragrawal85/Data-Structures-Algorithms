#include <bits/stdc++.h>
using namespace std;

/*bitmask reduces intersection time significantly
code to find number of days of the most overlapping work days*/

void printbinary(int num)
{
    for (int i = 9; i >= 0; i--)
    {
        cout << (num >> i & 1);
    }
    cout << endl;
}
int main()
{
    cout << "Enter the number of workers:";
    int n;
    cin >> n;
    vector<int> mask(n, 0);
    cout << "Enter number of days & days for:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        int t;
        cin >> t;
        int m = 0;
        for (int i = 0; i < t; i++)
        {
            int k;
            cin >> k;
            m = m | 1 << k;
        }
        mask[i] = m;
    }
    for (auto x : mask)
        printbinary(x);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int hold = mask[i] & mask[j];
            ans = max(ans, __builtin_popcount(hold));
        }
    }
    cout << ans << endl;
}