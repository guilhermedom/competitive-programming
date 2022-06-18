#include <stdio.h>

int main()
{
    int m, n, i, a, ver = 0, esp = 0, res = 0;
    char c;
    scanf("%d%d", &n, &m);
    char vet[n];
    for (i = 0; i < n; i++)
    {
        vet[i] = '0';
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a);
        scanf("%c", &c);
        if (c == 'R')
            res++;
        if (c == 'E')
            esp++;
        if (vet[a-1] == '0')
            vet[a-1] = c;
        else
        {
            printf("Impossivel");
            ver = 1;
        }
    }
    if (ver == 0 && res <= 0.4 * n)
        printf("Possivel");
    if (res > 0.4 * n)
        printf("Impossivel");
    return 0;
}
