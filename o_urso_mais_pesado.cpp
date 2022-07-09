#include <cstdio>

using namespace std;

int main() {
    int a, b, i = 0;

    scanf("%d %d", &a, &b);

    while(1) {
        i++;
        a *= 3;
        b *= 2;
        if (a > b) {
            break;
		}
    }

    printf("%d\n", i);
	
    return 0;
}
