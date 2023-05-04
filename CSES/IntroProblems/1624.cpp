#include <bits/stdc++.h>

using namespace std;

int ans = 0;
string s[8];

string rdiag = "...............";
string ldiag = "...............";
string col = "........";

void count(int row)
{
    if(row == 8)
    {
        ans++;
        return;
    }

    for(int i = 0; i < 8; i++)
    {
        if(ldiag[i+row] == '*' || rdiag[row-i+7] == '*' || col[i] == '*' || s[row][i] == '*') continue;

        col[i] = ldiag[i+row] = rdiag[row-i+7] = '*';
        count(row + 1);
        col[i] = ldiag[i+row] = rdiag[row-i+7] = '.';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }
    count(0);
    cout << ans;
}