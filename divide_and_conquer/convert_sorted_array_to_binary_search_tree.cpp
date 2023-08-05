/**
 * 题目来源：https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return doSort(nums, 0, nums.size() - 1);
  }

  TreeNode* doSort(const vector<int>& nums, int begin, int end) {
    if (begin == end) {
      return new TreeNode(nums[begin]);
    }

    int middle = begin + (end - begin) / 2;
    TreeNode* root = new TreeNode(nums[middle]);
    if (middle == begin) {
      root->right = doSort(nums, begin + 1, end);
      return root;
    }
    if (middle == end) {
      root->left = doSort(nums, begin, end - 1);
      return root;
    }
    root->left = doSort(nums, begin, middle - 1);
    root->right = doSort(nums, middle + 1, end);
    return root;
  }
};