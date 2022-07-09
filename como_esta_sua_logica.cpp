#include <iostream>

using namespace std;

int main() {
    int i, n, x, count = 0;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) {
            count++;
        }
    }

    cout << count;

    return 0;
}
