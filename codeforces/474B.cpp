#include<bits/stdc++.h>

using namespace std;

int binSearch(int q, vector<int>& a) {
    int i = 0, j = a.size()-1;
    while(i < j) {
        int mid = (i + j)/2;
        if(a[mid] > q) {
            j = mid;
        }
        else if(a[mid] < q) {
            i = mid + 1;
        }
        else {
            return mid;
        }
    }
    return j;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 1; i < n; i++) a[i] += a[i-1];

    int m; cin >> m;
    vector<int> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i];
        cout << binSearch(q[i], a) + 1 << "\n";
    }
}