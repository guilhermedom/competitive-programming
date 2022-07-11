#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    string S;
    set <string> s;
    for (int i = 0; i < n; i++)
    {
        cin >> S;
        s.insert(S);
    }
    cout << s.size();

	return 0;
}