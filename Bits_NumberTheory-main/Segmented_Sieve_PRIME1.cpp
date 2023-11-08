#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
/*
    Generate all prime numbers between two given numbers
    m and n (1 <= m <= n <= 1000000000, n-m<=100000)
*/
vector<int> isPrime(sqrt(M) + 1, 1);
void solve()
{
    int l, h;
    cin >> l >> h;
    vector<int> curr_Primes;
    for (int i = 2; i < sqrt(h) + 10; i++)
    {
        if (isPrime[i])
            curr_Primes.push_back(i);
    }
    vector<int> segment_primes(h - l + 1, 1);
    for (auto x : curr_Primes)
    {
        int sm = (l / x) * x; // smallest_multiple

        if (sm < l)
            sm = sm + x; // if that is less than l increase by x

        for (int i = (sm == x) ? (2 * sm) : sm; i <= h; i += x) // start from 2*sm if smallest mult>l
            segment_primes[i - l] = 0;                          // is prime itself
    }
    for (int i = max(l, 2); i <= h; i++)
    {
        if (segment_primes[i - l])
            cout << i << '\n';
    }
}
int main()
{
    int n = sqrt(M);
    isPrime[1] = 0;
    isPrime[0] = 0;
    for (int i = 2; i < n + 1; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < n + 1; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}
// CHECK FOR OWN TESTCASES
