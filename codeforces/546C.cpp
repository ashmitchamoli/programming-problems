#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int k1; cin >> k1;
    deque<int> d1, d2;

    for(int i = 0; i < k1; i++)
    {
        int x; cin >> x;
        d1.push_front(x);
    }
    int k2; cin >> k2;
    for(int i = 0; i < k2; i++)
    {
        int x; cin >> x;
        d2.push_front(x);
    }

    int fights = 0;
    while()
    {
        if(d1.size() == 0)
        {
            cout << fights << " 1";
            break;
        }
        if(d2.size() == 0)
        {
            cout << fights << " 2";
            break;
        }
        if(/*cycle repeat*/)
        {

        }

        6
        fights++;
        int pkt1[2] = {0}, pkt2[2] = {0};
        pkt1[1] = d1.back(); pkt2[1] = d2.back();
        if(pkt1[1] < pkt2[1])
        {
            pkt2[0] = pkt1[1];
            pkt1[1] = 0;
        }
        else
        {
            pkt1[0] = pkt2[0];
            pkt2[1] = 0;
        }
        d1.pop_back(); d2.pop_back();
        d1.push_front(pkt1[0]); d1.push_back(pkt1[1]);
        d2.push_front(pkt2[0]); d2.push_back(pkt2[1]);
    }

}