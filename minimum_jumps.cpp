#include <bits/stdc++.h>

using namespace std;

int min_jumps_recursive(int *input_arr, int n, int pos) {
	if (pos >= n - 1) {
		return 0;
	}

	int curr;
	int min = INT_MAX;
	for (int i = 1; i <= input_arr[pos]; i++) {
		curr = min_jumps_recursive(input_arr, n, pos + i);
		if (curr < min) min = curr;
	}
	return min + 1;
}

int min_jumps_topdown(int *input_arr, int n, int pos, int *dp) {
	if (pos >= n - 1) {
		return 0;
	}

	if (dp[pos]) return dp[pos];

	int curr;
	int min = INT_MAX;
	for (int i = 1; i <= input_arr[pos]; i++) {
		curr = min_jumps_topdown(input_arr, n, pos + i, dp);

		if (curr < min) min = curr;
	}
	return dp[pos] = min + 1;
}

int min_jumps_bottomup(int *input_arr, int n, int *dp) {
	int i;
	dp[0] = 0;
	for (i = 0; i < n; i++) {
		for (int j = 1; j <= input_arr[i] && i + j < n; j++) {
			if (dp[i] + 1 < dp[i + j] || dp[i + j] == 0)
				dp[i + j] = dp[i] + 1;
		} 
	}

	return dp[n - 1];
}

int min_jumps_bottomup_linear(int *input_arr, int n) {
	int steps = input_arr[0];
	int jumps = 0;
	int max_range = 0;
	int ind_max_range = 0;

	for (int i = 1; i < n; i++) {
		if (i + input_arr[i] >= n - 1) {
			jumps += 2;
			break;
		}
		
		steps--;

		if (input_arr[i] > max_range) {
			max_range = input_arr[i];
			ind_max_range = i;
		}

		if (steps == 0) {
			steps = max_range;
			max_range = 0;
			i = ind_max_range;
			jumps++;
		}
	}

	return jumps;
}

void solve() {
	int n;
	cin >> n;

	int input_arr[n];

	for (int i = 0; i < n; i++) {
		cin >> input_arr[i];
	}
	//for(auto x : input_arr) cout << x << " "; cout << endl;

	int dp[n] = {0};
	cout << min_jumps_bottomup_linear(input_arr, n);
}

int main() {
	int t;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	clock_t z = clock();

	cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}