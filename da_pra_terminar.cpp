#include <bits/stdc++.h>

using namespace std;

int main () {
    int i, j, n, m, line, column;

    cin >> n;
    cin >> m;

    char mat[n][m];
    int mat2[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> mat[i][j];
            mat2[i][j] = 0;
        }
    }

    cin >> line;
    cin >> column;

    for (i = line; i < n;) {
        for (j = column; j < m;) {
            if (mat2[i][j] == 1) {
                cout << "EOQ";
                return 0;
            }
            mat2[i][j] = 1;
            if (mat[i][j] == 'L') {
                j -= 1;
                if (j < 0) {
                    cout << "AE MLK";
                    return 0;
                }
            }
            if (mat[i][j] == 'R') {
                j += 1;
                if (j >= m) {
                    cout << "AE MLK";
                    return 0;
                }
            }

            if (mat[i][j] == 'U') {
                i -= 1;
                if (i < 0) {
                    cout << "AE MLK";
                    return 0;
                }
            }

            if (mat[i][j] == 'D') {
                i += 1;
                if (i >= n) {
                    cout << "AE MLK";
                    return 0;
                }
            }
        }
    }
	
    return 0;
}
