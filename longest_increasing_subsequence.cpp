#include <bits/stdc++.h>

using namespace std;

int longest_increasing_subsequence_recursive(int *arr, int n, int pos, int *overall_longest) {
	int longest = 0;
	int candidate;
	for (int i = pos - 1; i >= 0; i--) {
		candidate = longest_increasing_subsequence_recursive(arr, n, i, overall_longest);
		if (arr[i] < arr[pos]) {
			longest = max(longest, candidate);
		}
	}

	*overall_longest = max(*overall_longest, longest + 1);

	return longest + 1;
}

int longest_increasing_subsequence_topdown(int *arr, int n, int pos, int *dp) {
	if (dp[pos]) {
		return dp[pos];
	}

	int longest = 0;
	int candidate;
	for (int i = pos - 1; i >= 0; i--) {
		candidate = longest_increasing_subsequence_topdown(arr, n, i, dp);
		if (arr[i] < arr[pos]) {
			longest = max(longest, candidate);
		}
	}

	return dp[pos] = longest + 1;
}

int longest_increasing_subsequence_bottomup(int *arr, int n, int *dp) {
	int longest_previous_subsequence;
	int longest_subsequence = 0;

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		longest_previous_subsequence = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				longest_previous_subsequence = max(longest_previous_subsequence, dp[j]);
			}
		}
		dp[i] = 1 + longest_previous_subsequence;
		longest_subsequence = max(longest_subsequence, dp[i]);
	}

	return longest_subsequence;
}

void solve() {
	int n;

	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int recursive_overall_longest = 0;
	int dp[n] = {0};

	cout << longest_increasing_subsequence_bottomup(arr, n, dp);
	//cout << recursive_overall_longest;
	// int longest = 0;
	// for (int i = 0; i < n; i++) {
	// 	longest = max(longest, dp[i]);
	// }
	// cout << longest;
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