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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
        queue<string> q({beginWord, "|"});
		unordered_map<string, bool> isVisited;

        int ans = 2;

        while(! q.empty()) {
            string currWord = q.front();
            q.pop();

			for (int i = 0; i < currWord.size(); i++) {
				char currChar = currWord[i];

				for (char c = 'a'; c <= 'z'; c++) {
					currWord[i] = c;

					for (auto word : wordList) {
						if (isVisited[word]) {
							continue;
						}

						if (currWord == word) {
                            if (word == endWord) {
                                return ans;
                            }
                            
                            q.push(word);
                            isVisited[word] = true;
						}
					}
				}
                currWord[i] = currChar;
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