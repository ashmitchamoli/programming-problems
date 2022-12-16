#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int a[10] = {0};
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '9')
        {
            a[3]+=2; a[2]++; a[7]++;
        }
        if(s[i] == '8')
        {
            a[2]+=3; a[7]++;
        }
        if(s[i] == '7')
        {
            a[7]++;
        }
        if(s[i] == '6')
        {
            a[3]++; a[5]++;
        }
        if(s[i] == '5')
        {
            a[5]++;
        }
        if(s[i] == '4')
        {
            a[3]++; a[2]+=2;
        }
        if(s[i] == '3')
        {
            a[3]++;
        }
        if(s[i] == '2')
        {
            a[2]++;
        }
    }

    for(int i = 9; i > 1; i--)
    {
        for(int j = 0; j < a[i]; j++)
        {
            cout << i;
        }
    }
    cout << '\n';
}