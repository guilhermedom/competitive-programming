#include <bits/stdc++.h>

using namespace std;

int main() {
    ios :: sync_with_stdio(false);

    int n = 5, r = -1;
    float dif = 5;

    while (1) {
        dif = ceil(dif / 2);

        cout << n << endl;
        fflush(stdout);
        cin >> r;

        if (r == 2)
            exit(0);
        else if (r == 0) {
            n -= dif;
        }
        else {
            n += dif;
        }
    }
	
    return 0;
}
