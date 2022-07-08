#include <bits/stdc++.h>

using namespace std;

int main () {
    int i, j, n, x1, x2, sum = 0, min = INT_MAX, pos;
    int dist, dist1, dist2, distA = INT_MAX, distB = INT_MAX;
    vector<int> v;

    cin >> n;
    cin >> x2;
    v.push_back(x2);

    for (i = 1; i < n; i++) {
        x1 = x2;
        cin >> x2;
        v.push_back(x2);
        sum += (x2 - x1);
    }

    for (i = 0; i < n; i++) {
        dist1 = v[i] - v.front();
        dist2 = v.back() - v[i];
        dist = dist1 + dist2;

        if (dist < min && (dist1 < distA || dist2 < distB)) {
            min = dist;
            pos = i;
        }
    }
    cout << v[pos];

    return 0;
}
