#include <bits/stdc++.h>

using namespace std;

int target_sum(vector<int> nums, int i, int target, int sum, char operation) {
	if (operation == '+') {
		sum += nums[i];
	}
	else {
		sum -= nums[i];
	}

	if (i == nums.size() - 1) {
		if (sum == target) {
			return 1;
		}
		return 0;
	}

	int ans = 0;
	ans += target_sum(nums, i + 1, target, sum, '+');
	ans += target_sum(nums, i + 1, target, sum, '-');
	return ans;
}

int findTargetSumWays(vector<int> nums, int target) {
	return target_sum(nums, 0, target, 0, '+') + target_sum(nums, 0, target, 0, '-');
}

void solve() {
	int n, target;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
 	cin >> target;

	cout << target_sum(nums, 0, target, 0, '+') + target_sum(nums, 0, target, 0, '-') << endl;
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