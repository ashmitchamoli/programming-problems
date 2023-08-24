#include <bits/stdc++.h>

using namespace std;

int main () {
    int _; cin >> _;
    while(_--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        s.push_back('0');
        reverse(s.begin(), s.end());
        int n = s.length();
        if(n == 2) {
            if(s[1] - '0' >= 5) {
                cout << "10\n";
            }
            else {
                cout << s[1] << "\n";
            }
            continue;
        }
        int first_i = n-1;
        for(int i = n-1; i > 0; i--) {
            if(s[i] - '0' >= 5) {
                int j = i-1;
                while(s[j] == '9') {
                    j--;
                }
                s[j]++;
                i = j+1;
                first_i = j;
            }
        }
        int i = (s[0] == '0');
        string ans(n-i, '0');
        int j = 0;
        for(; i <= first_i; i++, j++) {
            ans[j]=s[i];
        }
        cout << ans  << "\n";
    }
}