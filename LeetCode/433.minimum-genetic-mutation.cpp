#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
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

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q({startGene, "|"});
        set<string> words(bank.begin(), bank.end());
        // words.erase(startGene);
    
        int ans = 1;

        while(! q.empty()) {
            string currWord = q.front();
            // cout << currWord << " ";
            q.pop();

            vector<string> temp;
            for(auto word : words) {
                if (isNeighbour(word, currWord)) {
                    if (word == endGene) {
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
        return -1;
    }
};
// @lc code=end

