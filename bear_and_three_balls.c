#include <stdio.h>

int main()
{
    int n, p = 0, i, j, aux = 1002, aux1 = 1002;
    scanf("%d", &n);
    int vet[n];
    for (i = 0; i < n; i++)
        scanf("%d", &vet[i]);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (vet[i] == (vet[j] + 1) && vet[j] + 1 != aux)
            {
                aux =  vet[j] + 1;
                p++;
            }
            else if(vet[i] == (vet[j] - 1) && vet[j] - 1 != aux1)
            {
                aux = vet[j] - 1;
                p++;
            }
            if (p == 2)
                break;
        }
        aux = 1002;
        aux1 = 1002;
        if (p == 2)
        {
            printf("YES");
            break;
        }
        else
            p = 0;
    }
    if (p == 0)
        printf("NO");
    return 0;
}
