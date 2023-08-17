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
    ListNode* sortList(ListNode* head) {
        if (!head || !(head->next)) {
          return head;
        }

        ListNode* first = head;
        ListNode* second = FindHalf(head);
        ListNode* sort_first = sortList(first);
        ListNode* sort_second = sortList(second);
        return Merge(sort_first, sort_second);
    }

    ListNode* FindHalf(ListNode* head) {
      ListNode* one_step = head;
      ListNode* two_step = head;
      while (two_step->next && two_step->next->next) {
        one_step = one_step->next;
        two_step = two_step->next->next;
      }

      ListNode* res = one_step->next;
      one_step->next = nullptr;
      return res;
    }

    ListNode* Merge(ListNode* first, ListNode* second) {
      ListNode* null_node = new ListNode(0);
      ListNode* res = null_node;
      while (first && second) {
        if (first->val <= second->val) {
          null_node->next = first;
          first = first->next;
        } else {
          null_node->next = second;
          second = second->next;
        }
        null_node = null_node->next;
      }
      if (!first) {
        null_node->next = second;
        return res->next;
      }
      null_node->next = first;
      return res->next;
    }
};