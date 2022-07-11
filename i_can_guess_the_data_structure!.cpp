#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
    int n, a, b, aux, popCount;
    vector<int> v1, v2;
    stack<int> stacker;
    queue<int> queuer;
    priority_queue<int> priority_queuer;

    while (scanf("%d", &n) != EOF) {
        v1.clear();
        popCount = 0;
        aux = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if (a == 1) {
                stacker.push(b);
                queuer.push(b);
                priority_queuer.push(b);
            }
            else {
                v1.push_back(b);
                popCount++;
            }
        }

        for (int i = 0; i < popCount; i++) {
            v2.push_back(stacker.top());
            stacker.pop();
        }

        if (v1 == v2) {
            aux++;
        }

        v2.clear();

        for (int i = 0; i < popCount; i++) {
            v2.push_back(queuer.front());
            queuer.pop();
        }

        if (v1 == v2) {
            aux += 2;
        }

        v2.clear();

        for (int i = 0; i < popCount; i++) {
            v2.push_back(priority_queuer.top());
            priority_queuer.pop();
        }

        if (v1 == v2) {
            aux += 3;
        }

        v2.clear();

        while (!stacker.empty())
            stacker.pop();
        while (!queuer.empty())
            queuer.pop();
        while (!priority_queuer.empty())
            priority_queuer.pop();

        switch (aux) {
            case 0:
            cout << "impossible\n";
            break;
            case 1:
            cout << "stack\n";
            break;
            case 2:
            cout << "queue\n";
            break;
            case 3:
            cout << "priority queue\n";
            break;
            default:
            cout << "not sure\n";
            break;
        }
    }

    return 0;
}
