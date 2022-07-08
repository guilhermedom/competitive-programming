#include <bits/stdc++.h>

using namespace std;

int main () {
    int i, j, n, x2, sum = 0, min = 1000000, pos;

    cin >> n;

    vector<int> v;

    for (i = 0; i < n; i++) {
        cin >> x2;
        v.push_back(x2);
    }

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += abs(v[j] - v[i]);
        }
        if (sum < min)
        {
            min = sum;
            pos = i;
        }
    }
    cout << v[pos];

    return 0;
}
