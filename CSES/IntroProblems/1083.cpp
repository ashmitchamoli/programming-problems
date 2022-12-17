#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n]; 
    bool b[n] = {false};
    for(int i = 0; i < n-1; i++)
    {
        cin >> a[i];
        b[a[i] - 1] = true;
    }
    for(int i = 0; i < n; i++)
    {
        if(b[i] == false)
        {
            cout << i + 1;
            return 0;
        }
    }
}