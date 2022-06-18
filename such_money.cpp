#include <stdio.h>

int main()
{
    int n, i, maior = 0, menor = 1000000000;
    scanf("%d", &n);
    int vet[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
        if (vet[i] > maior)
            maior = vet[i];
        if (vet[i] < menor)
            menor = vet[i];
    }
    printf("%d", maior - menor);
    return 0;
}
