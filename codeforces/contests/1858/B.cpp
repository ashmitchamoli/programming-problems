#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n,m,d; cin >> n >> m >> d;
        vector<int> s(m+2);
        s[0] = 1;
        for(int i = 1; i <= m; i++) cin >> s[i];
        s[m+1] = n+1;
        int max_decrease = 0;
        int num_cookies = 0;
        int num_sellers = 0;
        for(int i = 1; i <= m; i++) {
            int prev = (s[i] - s[i-1] - 1)/d + (s[i+1] - s[i] - 1)/d;
            int now = (s[i+1]-s[i-1]-1)/d;
            num_cookies += prev;
            if(max_decrease <= prev-now) {
                if(max_decrease == prev-now) {
                    num_sellers++;
                    continue;
                }
                num_sellers = 1;
                max_decrease = prev - now;
            }
        }
        if(max_decrease == 0) {
            int x = 0;
            for(int i = 1; i <= m; i++) {
                if((s[i] - s[i-1])%d == 0) {
                    x++;
                }
            }
            cout << num_cookies + (m-x) << " " << x << "\n";
            continue;
        }
        if(s[1] != 1) num_cookies++;
        cout << num_cookies + (m-1) - max_decrease << " " << num_sellers << "\n";
    }
}