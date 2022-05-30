#include <bits/stdc++.h>

using namespace std;

void brackets(int n, char *str, int i, int open_par, int unpaired_par) {
	if (i == n * 2) {
		cout << str << endl;
		return;
	}

	if (unpaired_par > 0) {
		str[i] = ')';
		brackets(n, str, i + 1, open_par, unpaired_par - 1);
	}

	if (open_par < n) {
		str[i] = '(';
		brackets(n, str, i + 1, open_par + 1, unpaired_par + 1);
	}
}

void solve() {
	int n;
	cin >> n;

	char *str = (char *) malloc((n * 2 + 1) * sizeof(char));
	brackets(n, str, 0, 0, 0);
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