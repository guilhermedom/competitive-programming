#include <iostream>

using namespace std;

int main() {
    int n, m, i, j, k, solutions = 0;

    cin >> n;
    cin >> m;

    char mat[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (mat[i][j] == 'D') {
                for (k = i; k < n; k++) {
                    if (mat[k][j] != '#') {
                        mat[k][j] = 'V';
					}
                    else {
                        break;
					}
                }
            }

            if (mat[i][j] == 'L') {
                for (k = j; k >= 0; k--) {
                    if (mat[i][k] != '#') {
                        mat[i][k] = 'V';
					}
                    else {
                        break;
					}
                }
            }

            if (mat[i][j] == 'R') {
                for (k = j; k < m; k++) {
                    if (mat[i][k] != '#') {
                        mat[i][k] = 'V';
					}
                    else {
                        break;
					}
                }
            }

            if (mat[i][j] == 'U') {
                for (k = i; k >= 0; k--) {
                    if (mat[k][j] != '#') {
                        mat[k][j] = 'V';
					}
                    else {
                        break;
					}
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                solutions++;
            }
        }
    }

    if (solutions == 0) {
        cout << "NO SOLUTION" << endl;
	}
    if (solutions == 1) {
        cout << "ONLY ONE SOLUTION" << endl;
	}
    if (solutions > 1) {
        cout << "MULTIPLE SOLUTIONS" << endl;
	}

    return 0;
}
