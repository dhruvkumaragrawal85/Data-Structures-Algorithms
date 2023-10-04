#include <bits/stdc++.h>
using namespace std;
int main()
{
     bitset<8> arr(14), brr(5);
     cout << "14  :" << arr << "\n"
          << "5   :" << brr << endl;
     cout << "14^5:" << (arr ^ brr) << endl;

     // optimized knapsack, O(n*w/32)
     int n, w;
     cin >> n >> w;
     bitset<100000> hold;
     hold[0] = 1;
     for (int i = 0; i < n; i++)
     {
          int x;
          cin >> x;
          hold = hold | hold << x;
     }
     cout << hold[w];
}
