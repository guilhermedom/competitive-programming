#include <bits/stdc++.h>

using namespace std;

int main() {
    ios :: sync_with_stdio(false);

    int n, m, num;

    cin >> n;
    cin >> m;

    vector<int> v, v2;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < m; i++) {
        v2.clear();
        cin >> num;
        for (int j = 0; j < n; j++) {
            v2.push_back(abs(v.at(j) - num));
        }
        for (int j = 0; j < n; j++) {
            cout << v2[j];
        }
        cout << v.at(lower_bound(v2.begin(), v2.end(), 0) - v2.begin()) << endl;
    }
	
    return 0;
}
