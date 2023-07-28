#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        set<int> a, b;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a.insert(x);
        }
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            b.insert(x);
        }
        bool aTurn = true;
        while(a.size() != 0 || b.size() != 0) {
            if(aTurn) {
                int x = *(a.rend()+1);
                a.extract(x);

            }
            aTurn = !aTurn;
        }
        
    }
}