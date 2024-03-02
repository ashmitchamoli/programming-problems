#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    bool isNeighbour(string word, string neighbour) {
        if (word.size() != neighbour.size()) {
            return false;
        }

        int count = 0;
        for (int i = 0; i < word.size(); i++) {
            count += (word[i] != neighbour[i]);
            if (count > 1) {
                return false;
            }
        }
        if (count == 1) {
            return true;
        }
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
        queue<string> q({beginWord, "|"});
        set<string> words(wordList.begin(), wordList.end());
        // words.erase(beginWord);
    
        int ans = 2;

        while(! q.empty()) {
            string currWord = q.front();
            // cout << currWord << " ";
            q.pop();

            vector<string> temp;
            for(auto word : words) {
                if (isNeighbour(word, currWord)) {
                    if (word == endWord) {
                        return ans;
                    }

                    q.push(word);

                    // words.erase(word);
                    temp.push_back(word);
                }
            }
            for (auto word : temp) {
                words.erase(word);
            }

            if (q.front() == "|") {
                // cout << " |\n";
                q.pop();
                ans++;
                if (q.empty()) {
                    break;
                }

                q.push("|");
            }
        }
        return 0;
    }
};
// @lc code=end