#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s, i, j, aux = 2, inter;
    cin >> n >> s;
    int vet[n];

    for (i = 0; i < n; i++)
        scanf("%d", &vet[i])

    for (k = 0; k < n; k++)
    {
        for (i = 0; i <= n - aux; i++)
        {
            for (j = i + 1; j < i + aux && j < n; j++)
            {
                if (vet[i] + vet[j] == s)
                {
                    printf("%d", (j - 1) + 1);
                    return 0;
                }
            }
        }
        aux++;
    }
    printf("-1");
}
