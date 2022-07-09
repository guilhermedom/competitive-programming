#include <bits/stdc++.h>
#include <array>

using namespace std;

void dfs(int u, int f, int *vis, array<vector<int>, 100000> &nodes) {
    vis[u] = 1;
    for (int i = 0; i < nodes[u].size(); i++) {
        int v = nodes[u][i];

        if (v == f)
        {
            cout << "SIM" << endl;
            exit(0);
        }

        if (vis[v] == 0) {
            dfs(v, f, vis, nodes);
		}
    }
}

int main() {
    int n, m, a, b, c, d;

    cin >> n;
    cin >> m;
    cin >> a;
    cin >> b;

    if (a == b) {
        cout << "SIM\n";
        return 0;
    }

    array<vector<int>, 100000> nodes;
    int vis[n+1] = {0};

    for (int i = 0; i < m; i++) {
        cin >> c;
        cin >> d;

        nodes[c].push_back(d);
    }

    dfs(a, b, vis, nodes);

    cout << "NAO\n";
	
    return 0;
}
