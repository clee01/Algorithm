/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/2378/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode node;
        doReverse(&node, head);
        return node.next;
    }

    void doReverse(ListNode* prev, ListNode* head) {
        if (!head) {
            return;
        }
        ListNode* next = head->next;
        head->next = prev->next;
        prev->next = head;
        doReverse(prev, next);
    }
};