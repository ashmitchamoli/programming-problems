#include <bits/stdc++.h>

using namespace std;

void dfs(int u, bool isVisited[], vector<int> graph[])
{
    if(isVisited[u]) return;
    isVisited[u] = true;
    for(int v : graph[u])
    {
        dfs(v, isVisited, graph);
    }
    return;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int m; cin >> m;
        string r1, r2; cin >> r1 >> r2;
        string s = r1 + r2;

        vector<int> graph[2*m];
        vector<int> blacks;
        for(int i = 0; i < 2*m; i++)
        {
            if(s[i] == 'B')
                blacks.push_back(i);
        }
        for(int i = 0; i < m; i++)
        {
            if(s[i] == 'B')
            {
                if(i != m && s[i+1] == 'B')
                {
                    graph[i].push_back(i+1);
                    graph[i+1].push_back(i);
                }
                if(s[i+m] == 'B')
                {
                    graph[i].push_back(i+m);
                    graph[i+m].push_back(i);
                }
            }
        }
        for(int i = m; i < 2*m; i++)
        {
            if(s[i] == 'B')
            {
                if(i != 2*m && s[i+1] == 'B')
                {
                    graph[i].push_back(i+1);
                    graph[i+1].push_back(i);
                }
            }
        }

        if(m == 1)
        {
            cout << "YES\n";
            continue;
        }

        int count = 0, count0 = 0;
        for(int i = 0; i < 2*m; i++)
        {
            if(s[i] == 'W') continue;
            if(graph[i].size() == 0) count0++;
            else if(graph[i].size()%2 == 1) count++;
        }

        if(count0 > 0) cout << "NO\n";
        else if(count%2 == 1) cout << "NO\n";
        else cout << "YES\n";
    }
}