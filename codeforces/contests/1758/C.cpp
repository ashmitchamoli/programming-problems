#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n, x; cin >> n >> x;
        if(n%x == 0) {
            cout << x << " ";
            int j = 2;
            for(int i = 2; i < n; i++) {
                if((j-1)*x == i) {
                    while((j*x) % i != 0 || (n % (j*x) != 0))  {
                        j++;
                    } 
                    cout << x*j << " ";
                    j++;
                    continue;
                }
                cout << i << " ";
            }
            cout << "1\n";
        
        }
        else {
            cout << "-1\n";
        }
        
    }
}