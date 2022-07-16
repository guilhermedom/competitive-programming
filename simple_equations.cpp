#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
    int n, a, b, c, x, y, z, min, i_min;
    vector<int> v;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        for (x = -100; x < 100; x++) {
            for (y = -100; y < 100; y++) {
                for (z = -100; z < 100; z++) {
                    if (x + y + z == a && x * y * z == b && (z*z) +
                    (y * y) + (x * x) == c) {
                        v.push_back(x);
                        v.push_back(y);
                        v.push_back(z);
                    }
                }
            }
        }
        if (v.empty()) {
            printf("No solution.\n");
            continue;
        }

        min = INT_MAX;
        i_min = 0;
        for (x = 0; x < (int) v.size(); x += 3) {
            if (v[x] < min) {
                min = v[x];
                i_min = x;
            }
        }
        printf("%d %d %d", v[i_min], v[i_min + 1], v[i_min + 2]);
    }

    return 0;
}
