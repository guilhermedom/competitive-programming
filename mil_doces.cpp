#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i, j, ca, f = 0, aux = 1;
    long long int total = 0;
    cin >> n >> m;
    int cal[n];

    for (i = 0; i < n; i++)
        cin >> cal[i];

    int tam = sizeof(cal) / sizeof(cal[0]);
    sort(cal, cal + tam);
    total += cal[0];

    for (i = 0; i < m; i++)
    {
        cin >> ca;
        for (j = aux; j < n; j++)
        {
            if (ca >= total)
            {
                f++;
                total += cal[j];
            }
            else
            {
                aux = j;
                break;
            }
        }
        cout << f << endl;
    }
}
