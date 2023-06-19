#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.length();
        int freq[128] = {0};
        int max_window_size = 0;
        while(i < n && j < n) {
            freq[s[j]]++;
            if(freq[s[j]] > 1) {
                while(freq[s[j]] > 1) {
                    freq[s[i]]--;
                    i++;
                }
            }
            max_window_size = max(max_window_size, j - i + 1);
            j++;
        }
        return max_window_size;
    }
};