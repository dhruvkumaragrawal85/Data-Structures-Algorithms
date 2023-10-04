#include <bits/stdc++.h>
using namespace std;
void printbinary(int num)
{
    for (int i = 9; i >= 0; i--)
    {
        cout << (num >> i & 1);
    }
    cout << endl;
}
void oddeven(int num)
{
    if (num & 1)
    {
        cout << "Number is odd.\n";
    }
    else
    {
        cout << "Number is even.\n";
    }
}
void mul2(int &num)
{
    num = num << 1;
}
void div2(int &num)
{
    num = num >> 1;
}
void chars()
{
    cout << "To convert upper to lowercase take (A | ' ')\nTo convert lower to upper case take (a & '_')\n";
    cout << "lowercase(A): "
         << "(A | ' ')=" << (char)('A' | ' ') << endl;
    cout << "uppercase(b): "
         << "(b & '_')=" << (char)('b' & '_') << endl;
}
void clearlsb(int &n)
{
    cout << "Enter bit upto which we have to clear LSB:";
    int i;
    cin >> i;
    n = n & (~((1 << (i + 1)) - 1));
    cout << "Number now:";
    printbinary(n);
}
void powof2(int n)
{
    if (n & n - 1)
        cout << "Not a power of 2.\n";
    else
        cout << "Number is a power of 2.\n";
}
int main()
{
    cout << "Enter number of testcase:";
    int t;
    cin >> t;
    while (t--)
    {
        cout << "Enter a number:";
        int n;
        cin >> n;
        cout << n << ":";
        printbinary(n);

        while (true)
        {
            cout << "Pick operation\n 1:Check odd/even\n 2:Multiply by 2\n 3:Divide by 2\n 4:See character conversion\n 5:Clear x lsb\n 6:Check if num is a power of two\n 7:Exit\n";
            int k;
            cin >> k;
            if (k == 7)
                break;
            switch (k)
            {
            case 1:
                oddeven(n);
                break;
            case 2:
                mul2(n);
                cout << "New num: " << n << ' ';
                printbinary(n);
                break;
            case 3:
                div2(n);
                cout << "New num: " << n << ' ';
                printbinary(n);
                break;
            case 4:
                chars();
                break;
            case 5:
                clearlsb(n);
                break;
            case 6:
                powof2(n);
                break;
            default:
                break;
            }
        }
    }
}