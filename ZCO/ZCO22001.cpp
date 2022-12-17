#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int ma[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> ma[i][j];
        }
    }
    int q; cin >> q;
    pair<int, int> Q[q][2];
    for(int i = 0; i < q; i++)
    {
        cin >> Q[i][0].first >> Q[i][0].second >> Q[i][1].first >> Q[i][1].second;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j==0) continue;
            ma[i][j] += ma[i][j-1]; 
        }
    }
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(i==0) continue;
            ma[i][j] += ma[i-1][j];
        }
    }
    
    for(int i = 0; i < q; i++)
    {
        int a = Q[i][0].first-1, b = Q[i][0].second-1, c = Q[i][1].first-1, d = Q[i][1].second-1;
        int ones = ma[c][d];
        if(a > 0)
            ones -= ma[a-1][d];
        if(b > 0)
            ones -= ma[c][b-1];
        if(a > 0 && b > 0)
            ones += ma[a-1][b-1];
        if(ones < ((c-a+1)*(d-b+1)))
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
}