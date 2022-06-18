#include <iostream>

using namespace std;

int main()
{
	int p;

	cin >> p;

	if(p == 2)
	    cout << "0\n";
    else
    {
	    cout << "1\n";
        int a = 1 + (p - 1) / 2;
        int b = (p - 1) / 2;
        cout << a << " " << b << "\n";
	}
	return 0;
}
