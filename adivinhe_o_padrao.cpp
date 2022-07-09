#include <iostream>

using namespace std;

int main() {
    int n, m, pattern1, pattern2, pattern3;

    cin >> n;
    cin >> m;

    long long int mat[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        pattern1 = 0;
        pattern2 = 0;
        pattern3 = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][j] > mat[i-1][j]) {
                pattern1++;
            }
            else if (mat[i][j] == mat[i-1][j]) {
                pattern2++;
            }
            else {
                pattern3++;
            }
        }

        if (pattern1 == n - 1 || pattern2 == n - 1 || pattern3 == n - 1) {
            cout << 'S' << endl;
        }
        else {
            cout << 'N' << endl;
		}
    }

    return 0;
}
