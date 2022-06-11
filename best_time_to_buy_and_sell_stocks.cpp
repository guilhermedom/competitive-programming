#include <bits/stdc++.h>

using namespace std;

int bestTimeToBuyAndSellStock_bottomup(int k, int *prices, int n) {
	if (n <= 1) {
		return 0;
	}

	int dp[k + 1][n + 1];

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i][j - 1];
			for (int k = 0; k < j; k++) {
				dp[i][j] = max(dp[i][j], prices[j] - prices[k] + dp[i - 1][k]);
			}
		}
	}

	return dp[k][n - 1];
}

void solve() {
	int k, n;

	cin >> k;
	cin >> n;

	int prices[n];

	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}

	cout << bestTimeToBuyAndSellStock_bottomup(k, prices, n);
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