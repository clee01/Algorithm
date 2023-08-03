/**
 * 题目来源：https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return doMerge(lists, 0, lists.size() - 1);
    }

    ListNode* doMerge(const vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int middle = start + (end - start) / 2;
        ListNode* left_node = doMerge(lists, start, middle);
        ListNode* right_node = doMerge(lists, middle + 1, end);
        return MergeTwo(left_node, right_node);
    }

    ListNode* MergeTwo(ListNode* left_node, ListNode* right_node) {
        if (!left_node) {
            return right_node;
        }
        if (!right_node) {
            return left_node;
        }
        ListNode res;
        ListNode* root = &res;
        while (left_node && right_node) {
            if (left_node->val < right_node->val) {
                root->next = left_node;
                left_node = left_node->next;
            } else {
                root->next = right_node;
                right_node = right_node->next;
            }
            root = root->next;
        }
        if (!left_node) {
            root->next = right_node;
        } else {
            root->next = left_node;
        }
        return res.next;
    }
};