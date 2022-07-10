#include <iostream>

using namespace std;

int main() {
    int i, j, n, x, count = 0;

    char mat[60];
    int v[6];

    for (i = 0; i < 60; i++) {
		cin >> mat[i];
    }

    for (i = 0; i < 6; i++) {
        cin >> v[i];
        if (mat[v[i] - 1] == 'x') {
            count++;
		}
    }

    if (count == 6) {
        cout << "S";
	} else {
        cout << "N";
	}

    return 0;
}
