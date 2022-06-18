#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, i, j, k, l, r, aux, soma = 0;
    scanf("%d", &n);
    int vet[n];

    for (i = 0; i < n; i++)
        scanf("%d" &vet[i]);

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d%d", &l, &r);
        aux = l;
        for (j = l; j < n, aux < r; j++)
        {
            if(vet[j] % aux == 0)
            {
                soma++;
            }
            aux++;
        }
        cout << soma << endl;
        soma = 0;
    }
}

