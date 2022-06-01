#include <bits/stdc++.h>

using namespace std;

int bestTimeToBuyAndSellStock_bottomup(int k, vector<int> prices) {
	vector<int> dp(prices.size());

	int min = prices[0];
	int max = 0;
	for (int i = 1; i < (int) prices.size(); i++) {
		if (max < prices[i]) {
			max = prices[i];
		} else {
			dp.push_back(i - 1);
			min = prices[i];
			max = 0;
		}
	}

	cout << dp.size();
	return 1;
}

void solve() {
	int k, n;

	cin >> k;
	cin >> n;
	vector<int> prices(n);

	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}

	bestTimeToBuyAndSellStock_bottomup(k, prices);
	// vector<vector<int>> dp(m, vector<int>(n, 0));
	// cout << collectingCoins_topdown(matrix, m - 1, n - 1, dp);
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