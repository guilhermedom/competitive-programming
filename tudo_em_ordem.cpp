#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, j, ver = 0;
    cin >> n >> m;
    int mat[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m - 1; j++)
        {
            if (mat[i][j] <= mat[i][j+1])
                ver++;
            else
                break;

        }
        if (ver == m - 1)
        {
            printf("S");
            return 0;
        }
        else
            ver = 0;
    }
    printf("N");
}
