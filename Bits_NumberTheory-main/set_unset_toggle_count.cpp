#include <bits/stdc++.h>
using namespace std;
void printbinary(int n)
{
    for (int i = 9; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
    return;
}
int main()
{
    cout << "Enter number of testcases:";
    int t;
    cin >> t;
    while (t--)
    {
        cout << "Enter number:";
        int k;
        cin >> k;
        printbinary(k);
        int i = 0;
        cout << "Enter bit number to be checked:";
        cin >> i;
        if ((1 << i) & k)
            cout << i << " bit is set.\n";
        else
            cout << "Bit is not set.\n";
        cout << "Enter bit number to set:";
        cin >> i;
        cout << "Old:";
        printbinary(k);
        cout << "New:";
        k = k | 1 << i;
        printbinary(k);
        cout << "Enter bit number to unset:";
        cin >> i;
        cout << "Old:";
        printbinary(k);
        cout << "New:";
        k = k & ~(1 << i);
        printbinary(k);
        cout << "Enter bit number to toggle:";
        cin >> i;
        cout << "Old:";
        printbinary(k);
        cout << "New:";
        k = k ^ (1 << i);
        printbinary(k);
        int count = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (1 << i & k)
                count++;
        }
        cout << "Number of set bits are:" << count << endl;
    }
}
