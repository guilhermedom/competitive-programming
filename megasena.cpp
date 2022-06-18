#include <bits/stdc++.h>

using namespace std;

int main()
{
    string l1, l2, l3, l4, l5, l6;
    char lt[60];
    int n1, n2, n3, n4, n5, n6, ver = 0, i, j = 0;

    cin >> l1;
    cin >> l2;
    cin >> l3;
    cin >> l4;
    cin >> l5;
    cin >> l6;

    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    cin >> n5;
    cin >> n6;

    for (i = 0; i < 10; i++)
    {
        lt[j] = l1[i];
        lt[j+10] = l2[i];
        lt[j+20] = l3[i];
        lt[j+30] = l4[i];
        lt[j+40] = l5[i];
        lt[j+50] = l6[i];
        j++;
    }

    if (lt[n1-1] == 'x')
        ver++;
    if (lt[n2-1] == 'x')
        ver++;
    if (lt[n3-1] == 'x')
        ver++;
    if (lt[n4-1] == 'x')
        ver++;
    if (lt[n5-1] == 'x')
        ver++;
    if (lt[n6-1] == 'x')
        ver++;

    if (ver == 6)
        cout << 'S';
    else
        cout << 'N';
}
