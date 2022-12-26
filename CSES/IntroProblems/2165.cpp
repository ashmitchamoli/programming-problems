#include <bits/stdc++.h>

using namespace std;

int mapping[6];

void print(int n, int i, int j)
{
    if(n == 1)
    {
        cout << i << " " << j << "\n";
        return;
    }

    print(n-1, i, mapping[i+j]);
    cout << i << " " << j << "\n";
    print(n-1, mapping[i+j], j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    mapping[3] = 3;
    mapping[5] = 1;
    mapping[4] = 2;
    int n; cin >> n;
    cout << (1<<n)-1 << "\n";
    print(n, 1, 3);
}