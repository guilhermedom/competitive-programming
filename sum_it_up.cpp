#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>

using namespace std;

void sums (vector<int> vector, int t, int sum, int i, int &je, vector<int> vector_r) {
    if (sum == t) {
        cout << vector_r[0];
        for (int j = 1; j < (int) vector_r.size(); j++) {
            cout << "+" << vector_r[j];
        }
        cout << endl;

        je++;
        return;
    }
	
    int previous = -1;
    for (; i < (int) vector.size(); i++) {
        if (vector[i] + sum <= t && previous != vector[i]) {
            vector_r.push_back(vector[i]);
            sums(vector, t, sum + vector[i], i+1, je, vector_r);
            vector_r.pop_back();
            previous = vector[i];
        }
    }
}

int main() {
    string line;
    int t, count, num;
    vector<int> vector, vector_r;
    string token;

    while (getline(cin, line)) {
        istringstream iss(line);

        if (!vector.empty()) {
            vector.clear();
		}
        if (!vector_r.empty()) {
            vector_r.clear();
		}

        count = 0;

        while (getline(iss, token, ' ')) {
            num = atoi(token.c_str());
            vector.push_back(num);
        }

        if (vector[0] == 0 && vector[1] == 0) {
            return 0;
        }

        cout << "Sums of %d:\n" << vector[0];
        t = vector[0];

        vector.erase(vector.begin());
        vector.erase(vector.begin());

        sums(vector, t, 0, 0, count, vector_r);

        if (count == 0) {
            cout << "NONE" << endl;
        }
    }

    return 0;
}
