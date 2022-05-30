#include <bits/stdc++.h>

using namespace std;

int perfectSquares_recursive(int n, vector<int> p_squares) {
	if (n == 0) {
		return 0;
	}
	if (n < 0) {
		return 9999;
	}

	int least_sum = 9999;
	int curr_sum;
	for (int i = p_squares.size() - 1; i >= 0; i--) {
		curr_sum = perfectSquares_recursive(n - p_squares[i], p_squares);
		least_sum = min(least_sum, curr_sum);
	}
	return least_sum + 1;
}

int perfectSquares_topdown(int n, vector<int> p_squares, int *dp) {
	if (n == 0) {
		return 0;
	}
	if (n < 0) {
		return 9999;
	}
	if (dp[n - 1]) {
		return dp[n - 1];
	}

	int least_sum = 9999;
	int curr_sum;
	for (int i = p_squares.size() - 1; i >= 0; i--) {
		curr_sum = perfectSquares_topdown(n - p_squares[i], p_squares, dp);
		least_sum = min(least_sum, curr_sum);
	}
	return dp[n - 1] = least_sum + 1;
}

int perfectSquares_bottomup(int n, vector<int> p_squares) {
	int least_sum;
	int curr_sum;
	int dp[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		least_sum = 9999;
		for (int j = p_squares.size() - 1; j >= 0; j--) {
			if (i - p_squares[j] >= 0) {
				curr_sum = dp[i - p_squares[j]] + 1;
				least_sum = min(least_sum, curr_sum);
			}
		}
		dp[i] = least_sum;
	}
	
	return dp[n];
}

void solve() {
	int n;

	cin >> n;

	int square = 1;
	vector<int> p_squares;
	for (int i = 2; square <= n; i++) {
		p_squares.push_back(square);
		square = i * i;
	}
	int dp[n] = {0};
	cout << perfectSquares_bottomup(n, p_squares);
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