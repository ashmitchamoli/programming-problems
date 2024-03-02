#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
*/

// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };


class Solution {
public:

    Node* createNode (vector<Node*>& graph, Node* oldNode) {
        if (graph[oldNode->val] != NULL) {
            return graph[oldNode->val];
        }

        Node* newNode = new Node(oldNode->val);
        graph[newNode->val] = newNode;

        for (auto& neighbour : oldNode->neighbors) {
            newNode->neighbors.push_back(createNode(graph, neighbour));
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        if (node->neighbors.size() == 0) {
            return new Node(node->val);
        }
        vector<Node*> graph(101);

        return createNode(graph, node);
    }
};
// @lc code=end

