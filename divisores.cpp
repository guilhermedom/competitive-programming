#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, i, j, k, l, r, aux, soma = 0, vetor;
    scanf("%d", &n);
    int vet[n];

    for (i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d%d", &l, &r);
        aux = l;
        j = 0;
        for (j = l; j < r; j++)
        {
            if (vet[j] < l)
            {
                soma += 2;
                continue;
            }
            for (k = 1; k <= vet[j] / 2; k++)
            {
                if(vet[j] % k == 0)
                {
                    soma++;
                }
            }
            soma++;
        }
        cout << soma << endl;
        soma = 0;
    }
}

