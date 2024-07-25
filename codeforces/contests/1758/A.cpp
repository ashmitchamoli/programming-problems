#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        string s; cin >> s;

        string s1 = s;
        reverse(s1.begin(), s1.end());
        s += s1;
        cout << s << "\n";
    }
}