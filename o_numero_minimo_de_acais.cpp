#include <bits/stdc++.h>

using namespace std;

int main () {
    string S, T;
    int i, counter = 0;

    getline(cin, S);
    getline(cin, T);

    for (i = 0; i < S.length(); i++) {
        if (S[i] != T[i]) {
            counter++;
		}
    }

    cout << counter;

    return 0;
}
