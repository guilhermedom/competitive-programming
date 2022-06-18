#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i, j, k, ca, f = 0, aux = 0;
    long long int total = 0;
    cin >> n >> m;
    int cal[n];

    for (i = 0; i < n; i++)
        cin >> cal[i];

    int tam = sizeof(cal) / sizeof(cal[0]);
    sort(cal, cal + tam);

    for (i = 0; i < m; i++)
    {
        cin >> ca;
        for (j = aux; j < n; j++)
        {
            total += cal[j];
            if (ca >= total)
                f++;
            else
            {
                total -= cal[j];
                aux = j;
                break;
            }
            if (j == n - 1)
            {
                cout << f << endl;
                for (k = i + 1; k < m; k++)
                {
                    cout << f << endl;
                }
                return 0;
            }
        }
        cout << f << endl;
    }
}
