    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int t; cin >> t;
        while(t--) {
            int n, x; cin >> n >> x;
            int n_odd = 0, temp = 0;
            for(int i = 0; i < n; i++) {
                cin >> temp;
                if(temp%2) n_odd++;  
            }
            if(n_odd == 0) {
                cout << "no\n";
            }
            else if(n_odd%2) {
                cout << "yes\n";
            }
            else {
                if(x%2) {
                    if(n > x) {
                        cout << "yes\n";
                    }
                    else {
                        cout << "no\n";
                    }
                }
                else {
                    if(n == n_odd || n == x) cout << "no\n";
                    else{
                        cout << "yes\n";
                    }
                }
            }
        }
    }