#include <bits/stdc++.h>

using namespace std;

int ans = 0;
string s;

void generate(int i, pair<int, int> curr, bool isVisited[7][7])
{
    if(i != 48 && isVisited[6][0])
    {
        return;
    }
    if(i == 48 && curr.first == 6 && curr.second == 0)
    {
        ans++;
        // cout << "\n";
        return;
    }
    else if(i == 48)
    {
        // cout << "\n";
        return;
    }
    if(s[i] != '?')
    {
        // cout << s[i];
        if(s[i] == 'D' && (curr.first == 6 || isVisited[curr.first+1][curr.second])) return;
        else if(s[i] == 'D')
        {
            curr.first++;
            isVisited[curr.first][curr.second] = true;
            generate(i+1, curr, isVisited);
            isVisited[curr.first][curr.second] = false;
            curr.first--;
        }
        if(s[i] == 'U' && (curr.first == 0 || isVisited[curr.first-1][curr.second])) return;
        else if(s[i] == 'U')
        {
            curr.first--;
            isVisited[curr.first][curr.second] = true;
            generate(i+1, curr, isVisited);
            isVisited[curr.first][curr.second] = false;
            curr.first++;
        }
        if(s[i] == 'L' && (curr.second == 0 || isVisited[curr.first][curr.second-1])) return;
        else if(s[i] == 'L')
        {
            curr.second--;
            isVisited[curr.first][curr.second] = true;
            generate(i+1, curr, isVisited);
            isVisited[curr.first][curr.second] = false;
            curr.second++;
        }
        if(s[i] == 'R' && (curr.second == 6 || isVisited[curr.first][curr.second+1])) return;
        else if(s[i] == 'R')
        {
            curr.second++;
            isVisited[curr.first][curr.second] = true;
            generate(i+1, curr, isVisited);
            isVisited[curr.first][curr.second] = false;
            curr.second--;
        }
        return;
    }
    if(curr.first != 6 && !isVisited[curr.first+1][curr.second])
    {
        // cout << "R";
        curr.first++;
        isVisited[curr.first][curr.second] = true;
        generate(i+1, curr, isVisited);
        isVisited[curr.first][curr.second] = false;
        curr.first--;
    }
    if(curr.first != 0 && !isVisited[curr.first-1][curr.second])
    {
        // cout << "L";
        curr.first--;
        isVisited[curr.first][curr.second] = true;
        generate(i+1, curr, isVisited);
        isVisited[curr.first][curr.second] = false;
        curr.first++;
    }
    if(curr.second != 6 && !isVisited[curr.first][curr.second+1])
    {
        // cout << "D";
        curr.second++;
        isVisited[curr.first][curr.second] = true;
        generate(i+1, curr, isVisited);
        isVisited[curr.first][curr.second] = false;
        curr.second--;
    }
    if(curr.second != 0 && !isVisited[curr.first][curr.second-1])
    {
        // cout << "U";
        curr.second--;
        isVisited[curr.first][curr.second] = true;
        generate(i+1, curr, isVisited);
        isVisited[curr.first][curr.second] = false;
        curr.second++;
    }
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    bool isVisited[7][7];
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            isVisited[i][j] = false;
    isVisited[0][0] = true;
    generate(0, make_pair(0, 0), isVisited);
    cout << ans;
}