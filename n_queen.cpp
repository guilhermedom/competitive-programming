#include <bits/stdc++.h>

using namespace std;

bool bad_column(int n, int **board, int row, int column) {
	for (int j = 0; j < row; j++) {
		if (board[j][column] == 1) {
			return true;
		}
	}
	return false;
}

bool bad_diagonals(int n, int **board, int row, int column) {
	for (int j = row - 1, k = column - 1; j >= 0 && k >= 0; j--, k--) {
		if (board[j][k] == 1) {
			return true;
		}
	}

	for (int j = row - 1, k = column + 1; j >= 0 && k < n; j--, k++) {
		if (board[j][k] == 1) {
			return true;
		}
	}
	return false;
}

bool nqueen(int n, int **board, int row) {
	if (row == n) {
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (bad_column(n, board, row, i)) continue;
		if (bad_diagonals(n, board, row, i)) continue;

		board[row][i] = 1;
		if (nqueen(n, board, row + 1)) {
			return true;
		} else {
			board[row][i] = 0;
		}
	}
	return false;
}

void nqueen_ways(int n, int **board, int row, int *solution_count) {
	if (row == n) {
		(*solution_count)++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (bad_column(n, board, row, i)) continue;
		if (bad_diagonals(n, board, row, i)) continue;

		board[row][i] = 1;
		nqueen_ways(n, board, row + 1, solution_count);
		board[row][i] = 0;
	}
}

void solve() {
	int n;
	cin >> n;

	int **board = (int **) calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++) {
		board[i] = (int *) calloc(n, sizeof(int));
	}

	if (nqueen(n, board, 0)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				cout << board[i][j] << "|";
			}
			cout << board[i][n - 1] << endl;
		}
	} else {
		cout << "No solution!" << endl;
	}
	// int solution_count = 0;
	// nqueen_ways(n, board, 0, &solution_count);
	// cout << solution_count << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}