#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits>

using namespace std;

int main() {
    int i, n, r;
    double x, y, xo = 0.0, yo = 0.0;
	double dist = numeric_limits<double>::max()
    cin >> r;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x;
        cin >> y;

        double dx = x - xo;
        double dy = y - yo;
        double euc = sqrt(dx * dx + dy * dy);

        double rx = xo + dx / euc * r;
        double ry = yo + dy / euc * r;

        euc = sqrt(pow(rx - x, 2) + pow(ry - y, 2));

        if (euc < dist) {
            dist = euc;
		}
    }
    cout << std::fixed << setprecision(9) << dist;
	
    return 0;
}
