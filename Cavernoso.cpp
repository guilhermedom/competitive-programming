#include <iostream>
#include <string.h>
#include <bits/c++io.h>

using namespace std;


int main()
{
    int n, i, vet[1000] = {0}, j, cont = 0, maior = 0;
    string c;
    getline(cin, c);
    for (i = 0; i < n; i++)
    {
        cin >> c;
        vet[strlen(c)]++;
    }
    for (i = 0; i < n; i++)
    {
        if (maior < vet[i])
            maior = vet[i];
    }
    cout << maior;
}
