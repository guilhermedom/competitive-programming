#include <iostream>

using namespace std;

int main() {
    long long int i, n, k;

    cin >> n;
    cin >> k;
	
    if (k == n) {
        cout << 1;
        return 0;
    }
	
    long long int factorial1 = 1;
    for (i = 2; i <= n; i++) {
        factorial1 *= i;
    }

    long long int factorial2 = 1;
    for (i = 2; i <= k; i++) {
        factorial2 *= i;
    }

    long long int factorial3 = 1;
    for (i = 2; i <= (n - k); i++) {
        factorial3 *= i;
    }

    cout << factorial1 / (factorial2 * factorial3);

    return 0;
}
