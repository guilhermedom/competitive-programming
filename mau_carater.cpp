#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s, soma = 0, i, j, k, aux = 2, inter, ajud1, ajud2;
    cin >> n >> s;
    int vet[n];

    for (i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    for (i = 0; i < n; i++)
    {
        if (vet[i] >= s)
        {
            printf("1");
            return 0;
        }
    }
    for (k = 1; k < n; k++)
    {
        ajud1 = n - aux;
        for (i = 0; i <= ajud1; i++)
        {
            ajud2 = i + aux;
            for (j = i; j < ajud2; j++)
            {
                soma += vet[j];
            }
            if (soma >= s)
            {
                printf("%d", aux);
                return 0;
            }
            soma = 0;
        }
        aux++;
    }
    printf("-1");
}
