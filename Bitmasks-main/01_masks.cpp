#include <bits/stdc++.h>
using namespace std;
void add(int &subset, int pos)
{
     subset = subset | (1 << (pos - 1));
}
void remove(int &subset, int pos)
{
     subset = subset & ~(1 << (pos - 1));
}
void display(int subset)
{
     for (int i = 0; i < 10; i++)
     {
          if (subset & 1 << i)
               cout << i + 1 << ' ';
     }
     cout << endl;
}
int main()
{
     int subset = 14;
     display(subset);
     remove(subset, 2);
     display(subset);
     add(subset, 6);
     display(subset);
}