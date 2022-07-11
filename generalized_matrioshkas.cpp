#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    string line;
    int aux, n, sum;
    stack<int> stacker;

    while (getline(cin, line)) {
        aux = 0;
        sum = 0;

        stringstream stream(line);
        while (stream >> n) {
            if (stacker.empty()) {
                stacker.push(n);
            }
            else if (abs(stacker.top()) != n && n > stacker.top()) {
                stacker.push(n);
            }
            else if (abs(stacker.top()) == n && n > sum) {
                stacker.pop();
                sum += abs(n);
            }
            else {
                cout << ":-( Try again.\n";
                aux = 1;
                break;
            }
        }
        if (aux == 1)
            continue;
        if (stacker.empty())
            cout << ":-) Matrioshka!\n";
        else
            cout << ":-( Try again.\n";
    }

    return 0;
}
