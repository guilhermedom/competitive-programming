#include <bits/stdc++.h>

using namespace std;

// int findTwoNonoverlappingSubArraysEachWithTargetSum_topdown(vector<int> arr, int i, bool firstDone, int sum, int target) {
// 	if (target == sum) {
// 		if (firstDone) {
// 			return i + 1;
// 		} else {
// 			findTwoNonoverlappingSubArraysEachWithTargetSum_topdown(arr, i + 1, true, 0, target);
// 		}
// 	}


// }

int findTwoNonoverlappingSubArraysEachWithTargetSum_bottomup(vector<int> arr, int target) {
	int sum = 0;
	int firstSmallest = 10001, secondSmallest = 10001;

	queue<int> aux;
	int j;

	for (int i = 0; i < arr.size(); i++) {
		aux.push(arr[i]);
		sum += arr[i];

		while (sum > target) {
			sum -= aux.front();
			aux.pop();
		}

		if (sum == target) {
			if (secondSmallest < firstSmallest) {
				swap(firstSmallest, secondSmallest);
			}
			secondSmallest = min(secondSmallest, (int) aux.size());
			sum = 0;
			aux = {};
		}
	}

	if (firstSmallest == 10001 || secondSmallest == 10001) {
		return -1;
	}

	return firstSmallest + secondSmallest;
}

void solve() {
	int target;
	vector<int> arr;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> target;
		arr.push_back(target);
	}
	cin >> target;

	cout << findTwoNonoverlappingSubArraysEachWithTargetSum_bottomup(arr, target);
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