// #include <bits/stdc++.h>
// using namespace std;
/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevNode = nullptr;

        while (head) {
            if (head->next && head->next->val == head->val) {
                while(head->next && head->val == head->next->val) {
                    head = head->next;
                }
                if (prevNode) {
                    prevNode->next = head->next;
                }
                else {
                    dummy->next = head->next;
                }
                head = head->next;
                continue;
            }
            prevNode = head;
            head = head->next;
        }
        return dummy->next;
    }
};
// @lc code=end

