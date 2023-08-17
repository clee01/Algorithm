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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> tmp;
        while (head) {
          tmp.emplace_back(head->val);
          head = head->next;
        }

        return doSort(tmp, 0, tmp.size() - 1);
    }

    TreeNode* doSort(const std::vector<int>& vec, int begin, int end) {
      if (begin > end) {
        return nullptr;
      }
      int middle = begin + (end - begin) / 2;
      TreeNode* node = new TreeNode(vec[middle]);
      node->left = doSort(vec, begin, middle - 1);
      node->right = doSort(vec, middle + 1, end);
      return node;
    }
};