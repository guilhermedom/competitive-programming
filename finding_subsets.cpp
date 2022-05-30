#include <bits/stdc++.h>

using namespace std;

void finding_subsets(char *str, int i, char *editable_str, int j) {
	if (str[i] == '\0') {
		editable_str[j] = '\0';
		cout << editable_str << endl;
		return;
	}
	
	editable_str[j] = str[i];
	finding_subsets(str, i + 1, editable_str, j + 1);
	finding_subsets(str, i + 1, editable_str, j);
}

void solve() {
	char *str;
	cin >> str;

	char *editable_str = (char *) malloc((strlen(str) + 1) * sizeof(char));

	finding_subsets(str, 0, editable_str, 0);
	free(editable_str);
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