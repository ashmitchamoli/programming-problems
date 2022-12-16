#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string n; cin >> n;
        cout << (n[0] - '0') + (n.length() - 1) * 9 << "\n"; 
    }
}