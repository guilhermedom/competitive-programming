#include <bits/stdc++.h>

using namespace std;

int powerSum(int x, int n, int i, int sum) {
	if (sum == x) {
		return 1;
	}
	if (sum > x) {
		return 0;
	}

	int count = 0;
	for (int j = i; j <= pow(x, 1 / float(n)); j++) {
		sum += pow(j, n);
		count += powerSum(x, n, j + 1, sum);
		sum -= pow(j, n);
	}

	return count;
}

void solve() {
	int x, n;

	cin >> x >> n;

	cout << powerSum(x, n, 1, 0);
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