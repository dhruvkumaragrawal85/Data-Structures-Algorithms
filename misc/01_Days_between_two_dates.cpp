#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
struct date
{
    int d, m, y;
};
vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_year(date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}
int date_diff(date date1, date date2)
{
    int days1 = 0, days2 = 0;
    days1 += 365 * date1.y + date1.d;
    days2 += 365 * date2.y + date2.d;
    for (int i = 0; i < date1.m - 1; i++)
    {
        days1 += months[i];
    }
    for (int i = 0; i < date2.m - 1; i++)
    {
        days2 += months[i];
    }
    days1 += leap_year(date1);
    days2 += leap_year(date2);
    return abs(days1 - days2);
}
void solve()
{
    date date1, date2;
    cout << "Enter 1st dd/mm/year:" << endl;
    cin >> date1.d >> date1.m >> date1.y;
    cout << "Enter 2nd dd/mm/year:" << endl;
    cin >> date2.d >> date2.m >> date2.y;
    cout << date_diff(date1, date2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
// LOGIC BEFORE CODE
// CHECK FOR YOUR OWN TESTCASES
