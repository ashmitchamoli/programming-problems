    #include <bits/stdc++.h>

    using namespace std;

    int main() {
        int _; cin >> _;
        while(_--) {
            long long w, f; cin >> w >> f;
            int n; cin >> n;

            long long wrem = 0, frem = 0;
            long long ans = 0;
            for(int i = 0; i < n; i++) {
                long long x; cin >> x;
                if(x <= wrem) {
                    wrem -= x;
                    continue;
                }
                else if(x <= frem) {
                    frem -= x;
                    continue;
                }

                long long wtime = ceil((double)(x - wrem)/w);
                long long ftime = ceil((double)(x - frem)/f);

                if(ftime < wtime) {
                    ans += ftime;
                    frem += ftime*f;
                    wrem += ftime*w;
                }
                else {
                    ans += wtime;
                    wrem += wtime*w;
                    frem += wtime*f; 
                }
            }
            cout << ans << "\n";
        }
    }