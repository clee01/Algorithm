/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1681/
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode prev;
        prev.next = head;
        doSwap(&prev);
        return prev.next;
    }

    void doSwap(ListNode* head) {
        if (!head->next || !head->next->next) {
            return;
        }

        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        head->next = next;
        curr->next = next->next;
        next->next = curr;
        doSwap(curr);
    }
};