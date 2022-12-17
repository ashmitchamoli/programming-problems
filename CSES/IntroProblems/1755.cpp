#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.size();

    int freq[26] = {0};
    for(char c : s)
    {
        freq[c - 'A']++;
    }
    int nOdd = 0;
    for(int i = 0; i < 26; i++)
    {
        nOdd += freq[i]%2;
    }
    if(nOdd > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        for(int i = 0; i < 26; i++)
        {
            if(freq[i]%2) continue;
            for(int j = 0; j < freq[i]/2; j++)
            {
                cout << (char) (i+'A');
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(nOdd == 0) break;
            if(freq[i]%2)
            {
                for(int j = 0; j < freq[i]; j++)
                {
                    cout << (char) (i+'A');
                }
                break;
            }
        }
        for(int i = 25; i > -1; i--)
        {
            if(freq[i]%2) continue;
            for(int j = 0; j < freq[i]/2; j++)
            {
                cout << (char) (i+'A');
            }
        }
    }
}