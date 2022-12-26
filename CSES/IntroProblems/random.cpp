#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binexp(int n)
{
    if(n == 1)
    {
        return 10;
    }
    if(n == 0)
    {
        return 1;
    }
    ll x = binexp(n/2);
    if(n%2)
    {
        ll y = (x*x);
        return (10*y);
    }
    else
    {
        return (x*x);
    }
}

int main()
{
    string s = "DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD";
    int freq[4] = {0};
    int mapping[1000];
    mapping['D'] = 0, mapping['U'] = 1, mapping['R'] = 2, mapping['L'] = 3; 
    for(char c: s)
    {
        freq[mapping[c]]++;
    }
    for(int i : freq)
    {
        cout << i << " ";
    }
}