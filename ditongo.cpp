#include <bits/stdc++.h>

using namespace std;

int main () {
    string input, output;
    string comp = "aeiouAEIOU";
    int i;

    getline(cin, input);

    output += input[0];

    for (i = 1; i < input.length(); i++) {
        if (comp.find(input[i]) == string::npos) {
            output += input[i];
        }

        else if (comp.find(input[i]) != string::npos && comp.find(input[i-1]) == string::npos) {
            output += input[i];
		}
    }

    cout << output;

    return 0;
}
