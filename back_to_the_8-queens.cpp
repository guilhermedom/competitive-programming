#include <cstdio>
#include <cstring>

using namespace std;

void solve(int col, int &num_sols, int (&line)[8], int (&diag1)[15], int (&diag2)[15], int (&check)[8], int (&all_sols)[100][8]) {
    if (col == 8) {
        for (int j = 0; j < 8; j++) {
            all_sols[num_sols][j] = check[j];
        }
        num_sols++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if ((diag1[i + col] == 1) || (diag2[7 - i + col] == 1) || (line[i] == 1)) {
            continue;
		}

        check[col] = i;

        line[i] = 1;
        diag1[i + col] = 1;
        diag2[7 - i + col] = 1;

        solve(col+1, num_sols, line, diag1, diag2, check, all_sols);

        line[i] = 0;
        diag1[i + col] = 0;
        diag2[7 - i + col] = 0;
    }
}

int main() {
    int i = 0, j, k, v[8], min, steps, num_sols = 0;
    int line[8], diag1[15], diag2[15], check[8], all_sols[100][8];

    solve(0, num_sols, line, diag1, diag2, check, all_sols);

    while (scanf("%d", &v[0]) == 1) {
        i++;

        for (j = 1; j < 8; j++) {
            scanf("%d", &v[j]);
        }

        min = 1000;
        for (j = 0; j < num_sols; j++) {
            steps = 0;
            for (k = 0; k < 8; k++) {
                if (all_sols[j][k] != v[k]) {
                    steps++;
				}
            }
            if (steps < min) {
                min = steps;
			}
        }
        printf("Case %d: %d\n", i, min);
    }
	
    return 0;
}
