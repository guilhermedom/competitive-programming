#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i = 0;
    string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string line;


    while (getline(cin, line)) {
        while (i < (int) line.size()) {
            if (line[i] == ' ') {
                cout << ' ';
                i++;
                continue;
            }
            cout << keyboard[keyboard.find(line[i]) - 1];
            i++;
        }
        i = 0;
        cout << "\n";
    }

	return 0;
}
