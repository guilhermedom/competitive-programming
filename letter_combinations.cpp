#include <bits/stdc++.h>

using namespace std;

map<char, string> dictionary;
vector<string> combinations;

void letterCombinationsPhoneNumber(string digits, int i, string str) {
	if (i == digits.size()) {
		combinations.push_back(str);
		return;
	}

	string current_button = dictionary[digits[i]];
	for (int j = 0; j < current_button.size(); j++) {
		str.push_back(current_button[j]);
		letterCombinationsPhoneNumber(digits, i + 1, str);
		str.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
    dictionary['2'] = "abc";
	dictionary['3'] = "def";
	dictionary['4'] = "ghi";
	dictionary['5'] = "jkl";
	dictionary['6'] = "mno";
	dictionary['7'] = "pqrs";
	dictionary['8'] = "tuv";
	dictionary['9'] = "wxyz";

	combinations.clear();

	if (digits.size() == 0) {
		return combinations;
	}

	letterCombinationsPhoneNumber(digits, 0, "");
	return combinations;
}

void solve() {
	dictionary['2'] = "abc";
	dictionary['3'] = "def";
	dictionary['4'] = "ghi";
	dictionary['5'] = "jkl";
	dictionary['6'] = "mno";
	dictionary['7'] = "pqrs";
	dictionary['8'] = "tuv";
	dictionary['9'] = "wxyz";
	string digits;

	cin >> digits;
	letterCombinationsPhoneNumber(digits, 0, "");
	for (int i = 0; i < combinations.size(); i++) {
		cout << combinations[i];
	}
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