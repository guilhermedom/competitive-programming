#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string word, word2;
    int i, j = 0, k = 0;
 
    cin >> word;
    cin >> word2;
 
    int wordSize = word.length() + word2.length();
    int wordSize1 = word.length();
    int wordSize2 = word2.length();
 
    for (i = 0; i < wordSize; i++)
    {
        if (j < wordSize1)
        {
            cout << word[i];
            j++;
        }
 
        if (k < wordSize2)
        {
            cout << word2[i];
            k++;
        }
    }
}