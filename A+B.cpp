#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    long int c;
    int i, j, n, qtd = 0, tam, num, d;

    cin >> n >> c;
    long int vet[n];

    for (i = 0; i < n; i++)
        cin >> vet[i];

    for (i = 0; i < n; i++)
    {
        d = c - vet[i];
        for (j = i + 1; j < n; j++)
        {
            while (vet[j] > d)
            {
                j = n / div;
                div++;
            }
            if (vet[j] == d)
                qtd++;
            if (vet[j] > d)
                break;
        }
    }
    cout << qtd;
}
