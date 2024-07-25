#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
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

    void getPaths(string currNode, vector<string>& currPath, vector<vector<string>>& paths, string& endNode, int pathLength,unordered_map<string, bool>& isVisited, vector<string>& wordList, vector<set<string>>& layers) {
        currPath.push_back(currNode);
        isVisited[currNode] = true;
        
        if(currNode == endNode && currPath.size() == pathLength) {
            paths.push_back(currPath);
            currPath.pop_back();
            isVisited[currNode] = false;
            cout << "found " << paths.size() << "\n"; 
            return;
        }

        if(currPath.size() == pathLength) {
            currPath.pop_back();
            isVisited[currNode] = false;
            return;
        }
        if (layers[currPath.size()-1].find(currNode) == layers[currPath.size()-1].end()) {
            currPath.pop_back();
            isVisited[currNode] = false;
            return;
        }

        for (auto word : wordList) {
            if (isVisited[word]) continue;

            if (isNeighbour(word, currNode)) {
                getPaths(word, currPath, paths, endNode, pathLength, isVisited, wordList, layers);
            }
        }

        // for (auto word : graph[currNode]) {
        //     if (isVisited[word]) continue;

        //     getPaths(word, currPath, paths, endNode, pathLength, isVisited, graph);
        // }

        currPath.pop_back();
        isVisited[currNode] = false;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q({beginWord, "|"});
        set<string> words(wordList.begin(), wordList.end());
        // vector<set<string>> layers(set<string>());
        vector<set<string>> layers({set<string>()});
        
        int ans = 1;

        bool found = false;

        while(! q.empty()) {
            string currWord = q.front();
            q.pop();

            // layers[layers.size() - 1].insert(currWord);
            layers[layers.size() - 1].insert(currWord);

            if (currWord == endWord) {
                found = true;
                break;
            }

            vector<string> temp;
            for(auto word : words) {
                if (isNeighbour(word, currWord)) {
                    q.push(word);

                    temp.push_back(word);
                }
            }
            for (auto word : temp) {
                words.erase(word);
            }

            if (found) break;
            if (q.front() == "|") {
                q.pop();
                ans++;
                if (q.empty()) {
                    break;
                }
                layers.push_back(set<string>());
                q.push("|");
            }
        }
        if (not found) {
            return vector<vector<string>>();
        }
        
        vector<vector<string>> paths;
        vector<string> currPath;
        unordered_map<string, bool> isVisited;
        getPaths(beginWord, currPath, paths, endWord, ans, isVisited, wordList, layers);
        return paths;
    }
};
// @lc code=end

