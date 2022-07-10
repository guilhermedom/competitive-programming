#include <iostream>

using namespace std;

int main() {
    long long int i, n;
    cin >> n;
	
    if (n % 2 == 1 || n == 1) {
        cout << n;
        return 0;
    }

    for (i = n / 2; i >= 0;) {
		if (i == 0 || i == 1) {
            cout << 1;
            return 0;
        }
        if (i % 2 == 0) {
            i = i / 2;
            continue;
        }
        if ((n % i == 0)) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
