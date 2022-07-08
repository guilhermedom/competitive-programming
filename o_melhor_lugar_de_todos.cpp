#include <bits/stdc++.h>

using namespace std;

int main () {
    int i, j, n, x1, x2, sum = 0;

    cin >> n;

    vector<int> v;

    cin >> x2;
    v.push_back(x2);

    for (i = 1; i < n; i++) {
        x1 = x2;
        cin >> x2;
        v.push_back(x2);
        sum += (x2 - x1);
    }

    int div = (sum / 2);

    if (std::find(v.begin(), v.end(), div) != v.end()) {
		cout << div;
		return 0;
    }

    for (i = div - 1, j = div + 1; i >= 0, j < x2; i--, j++) {
        if (std::find(v.begin(), v.end(), i) != v.end()) {
            cout << i;
            return 0;
        }
        if (std::find(v.begin(), v.end(), j) != v.end()) {
            cout << j;
            return 0;
        }
    }

    return 0;
}
