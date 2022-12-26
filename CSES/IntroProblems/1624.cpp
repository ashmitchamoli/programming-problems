#include <bits/stdc++.h>

using namespace std;

int ans = 0;
string s[8];

void count(int row, string diag, string col)
{
    if(row == 8)
    {
        ans++;
        return;
    }

    for(int i = 0; i < 8; i++)
    {
        if(diag[i] == '*' || col[i] == '*' || s[row][i] == '*') continue;

        string tcol = col, tdiag = diag;
        tcol[i] = '*';
        if(tdiag[7] == '*') tdiag[7] = '.';
        for(int j = 0; j < 7; j++)
        {
            if(tcol[j] == '*')
            {
                tcol[j] = '.';
                tcol[j+1] = '*';
            }
        }
        if(i < 7) tdiag[i+1] = '*';
        count(row + 1, tdiag, tcol);
    }
}

/*
........
........
..*.....
........
........
.....**.
...*....
........
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }

    count(0, "........", "........");
    cout << ans;
}