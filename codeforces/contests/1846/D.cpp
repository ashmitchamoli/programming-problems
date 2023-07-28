#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n, d, h; cin >> n >> d >> h;
        vector<int> y(n);
        for(int i = 0; i < n; i++) {
            cin >> y[i];
        }
        sort(y.begin(), y.end());
        double ov = 0;

        for(int i = 1; i < n; i++) {
            if(y[i] - y[i-1] < h) {
                double h_ = y[i-1] - y[i] + h;
                ov += h_ * ((double)0.5) * ((double)d) * h_ / ((double) h);
            }
        }
        double ans = (double) 0.5 * (double) n * (double) d * (double) h - ov;
        cout << setprecision(9) << ans << "\n";
    }
}