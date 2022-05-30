#include <bits/stdc++.h>

using namespace std;

int box_stacking_recursive(vector<vector<int>> arr, int n, int pos, int *overall_longest) {
	int max_height = 0;
	int candidate = 0;
	for (int i = pos - 1; i >= 0; i--) {
		candidate = box_stacking_recursive(arr, n, i, overall_longest);
		if (arr[i][0] < arr[pos][0] && arr[i][1] < arr[pos][1] && arr[i][2] < arr[pos][2]) {
			max_height = max(max_height, candidate);
		}
	}

	*overall_longest = max(*overall_longest, max_height + arr[pos][2]);

	return max_height + arr[pos][2];
}

int box_stacking_topdown(vector<vector<int>> arr, int n, int pos, int *dp) {
	int max_height = 0;
	int candidate = 0;

	if (dp[pos]) {
		return dp[pos];
	}

	for (int i = pos - 1; i >= 0; i--) {
		candidate = box_stacking_topdown(arr, n, i, dp);
		if (arr[i][0] < arr[pos][0] && arr[i][1] < arr[pos][1] && arr[i][2] < arr[pos][2]) {
			max_height = max(max_height, candidate);
		}
	}

	return dp[pos] = max_height + arr[pos][2];
}

int box_stacking_bottomup(vector<vector<int>> arr, int n) {
	vector<int> dp(n);
	dp[0] = arr[0][2];

	int max_height = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = arr[i][2];
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j][0] < arr[i][0] && arr[j][1] < arr[i][1] && arr[j][2] < arr[i][2]) {
				dp[i] = max(dp[i], arr[i][2] + dp[j]);
			}
		}
		max_height = max(max_height, dp[i]);
	}
	return max_height;
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n);

	int input_var;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input_var;
			arr[i].push_back(input_var);
		}
	}

	sort(arr.begin(), arr.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
		return lhs[2] < rhs[2];
	});

	int recursive_overall_longest = 0;
	int dp[n] = {0};
	cout << box_stacking_bottomup(arr, n);
	//cout << recursive_overall_longest;
	// int max_height = 0;
	// for (int i = 0; i < n; i++) {
	// 	max_height = max(max_height, dp[i]);
	// }
	// cout << max_height;
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