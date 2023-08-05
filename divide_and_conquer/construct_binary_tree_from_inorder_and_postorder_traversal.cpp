/**
 * 题目来源：https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return doBuild(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }

  TreeNode* doBuild(const vector<int>& inorder, const vector<int>& postorder, int start_i, int end_i, int start_p, int end_p) {
    if (start_i == end_i) {
        return new TreeNode(inorder[start_i]);
    }

    TreeNode* root = new TreeNode(postorder[end_p]);
    int index_i = Find(inorder, start_i, end_i, postorder[end_p]);
    if (index_i == start_i) {
        root->right = doBuild(inorder, postorder, start_i + 1, end_i, start_p, end_p - 1);
        return root;
    }
    if (index_i == end_i) {
        root->left = doBuild(inorder, postorder, start_i, end_i - 1, start_p, end_p - 1);
        return root;
    }
    root->left = doBuild(inorder, postorder, start_i, index_i - 1, start_p, start_p + index_i - start_i - 1);
    root->right = doBuild(inorder, postorder, index_i + 1, end_i, end_p - end_i + index_i, end_p - 1);
    return root;
  }
};