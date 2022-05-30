#include <bits/stdc++.h>

using namespace std;

void permutations(char *str, int i) {
	if (str[i] == '\0') {
		cout << str << endl;
		return;
	}

	for (int pos = i; pos < (int) strlen(str); pos++) {
		swap(str[i], str[pos]);
		permutations(str, i + 1);
		swap(str[i], str[pos]);
	}
}

void solve() {
	char *str;
	cin >> str;

	permutations (str, 0);
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