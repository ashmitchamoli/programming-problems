#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        long long n, m, d; cin >> n >> m >> d;
        vector<pair<long long, int>> a;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            if(x <= 0) continue;
            a.push_back({x, i});
        }
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> max_m;
        long long sum = 0;
        for(int i = 0; i < a.size(); i++) {
            if(max_m.size() < m) {
                max_m.push(a[i].first);
                sum += a[i].first;
                ans = max(ans, sum - a[i].second*d);
            }
            else if(max_m.top() < a[i].first) {
                sum -= max_m.top();
                sum += a[i].first;
                max_m.pop();
                max_m.push(a[i].first);
                ans = max(ans, sum - a[i].second*d);
            }
        }
        cout << ans << "\n";
    }
}