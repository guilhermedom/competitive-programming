#include <bits/stdc++.h>

using namespace std;

int collectingCoins_topdown(vector<vector<int>> matrix, int i, int j, vector<vector<int>> dp) {
	if (i == 0 && j == 0) {
		return matrix[i][j];
	}
	if (dp[i][j]) {
		return dp[i][j];
	}
	if (i == 0) {
		return matrix[i][j] + collectingCoins_topdown(matrix, i, j - 1, dp);
	}
	if (j == 0) {
		return matrix[i][j] + collectingCoins_topdown(matrix, i - 1, j, dp);
	}

	return dp[i][j] = matrix[i][j] + max(collectingCoins_topdown(matrix, i - 1, j, dp),
										 collectingCoins_topdown(matrix, i, j - 1, dp));
}

int collectingCoins_bottomup(vector<vector<int>> matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	vector<vector<int>> dp(m, vector<int>(n));

	dp[0][0] = matrix[0][0];

	for (int i = 1; i < m; i++) {
		dp[i][0] = matrix[i][0] + dp[i - 1][0];
	}

	for (int j = 1; j < n; j++) {
		dp[0][j] = matrix[0][j] + dp[0][j - 1];
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = matrix[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m - 1][n - 1];
}

void solve() {
	int m, n;

	cin >> m >> n;
	vector<vector<int>> matrix(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	// cout << collectingCoins_bottomup(matrix);
	vector<vector<int>> dp(m, vector<int>(n, 0));
	cout << collectingCoins_topdown(matrix, m - 1, n - 1, dp);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
	return 0;
}