#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s; cin >> s;
    int n = s.size();   
    int count = 1, max_count = 1;
    for(int i = 1; i < n; i++)
    {
        if(s[i] != s[i-1])
        {
            max_count = max(max_count, count);
            count = 0;
        }
        count++;
    }
    max_count = max(max_count, count);
    cout << max_count;
}