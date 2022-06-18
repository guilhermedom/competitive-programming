#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a, b, d;
    int i, j, ver = 0;

    cin >> a;
    cin >> b;
    cin >> d;

    if (a % 5 != 0)
        cout << (b / d) - (a / d);
    else
        cout << (b / d) - (a / d) + 1;
}
