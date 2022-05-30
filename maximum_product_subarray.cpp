#include <bits/stdc++.h>

using namespace std;

int maximumProductSubarray_topdown(vector<int> nums, int i, int *currMax, int *currMin) {
	if (i == 0) {
		*currMax = nums[i];
		*currMin = nums[i];
		return nums[i];
	}

	int maxProduct = maximumProductSubarray_topdown(nums, i - 1, currMax, currMin);
	if (nums[i] >= 0) {
		*currMax = max(nums[i], nums[i] * (*currMax));
		*currMin = min(nums[i], nums[i] * (*currMin));
	} else {
		int tmpMax = max(nums[i], nums[i] * (*currMin));
		*currMin = min(nums[i], nums[i] * (*currMax));
		*currMax = max(nums[i], tmpMax);
	}
	maxProduct = max(maxProduct, *currMax);

	return maxProduct;
}

int maximumProductSubarray_bottomup(vector<int> nums) {
	int maxProduct;
	int currMax, currMin, tmpMax;
	currMax = currMin = maxProduct = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] >= 0) {
			currMax = max(nums[i], nums[i] * currMax);
			currMin = min(nums[i], nums[i] * currMin);
		} else {
			tmpMax = max(nums[i], nums[i] * currMin);
			currMin = min(nums[i], nums[i] * currMax);
			currMax = max(nums[i], tmpMax);
		}
		maxProduct = max(maxProduct, currMax);
	}
	
	return maxProduct;
}

void solve() {
	int n;
	vector<int> nums;

	while (cin >> n) {
		nums.push_back(n);
	}

	// cout << maximumProductSubarray_bottomup(nums);
	int currMax, currMin;
	cout << maximumProductSubarray_topdown(nums, nums.size() - 1, &currMax, &currMin);
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