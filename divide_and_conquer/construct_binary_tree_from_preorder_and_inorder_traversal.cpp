/**
 * 题目来源：https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return doBuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* doBuild(const vector<int>& preorder, const vector<int>& inorder, int start_p, int end_p, int start_i, int end_i) {
        if (start_p == end_p) {
            return new TreeNode(preorder[start_p]);
        }
        TreeNode* root = new TreeNode(preorder[start_p]);
        int index_i = Find(inorder, start_i, end_i, preorder[start_p]);
        if (start_i == index_i) {
            root->right = doBuild(preorder, inorder, start_p + 1, end_p, start_i + 1, end_i);
            return root;
        }
        if (index_i == end_i) {
            root->left = doBuild(preorder, inorder, start_p + 1, end_p, start_i, end_i - 1);
            return root;
        }
        root->left = doBuild(preorder, inorder, start_p + 1, start_p + index_i - start_i, start_i, index_i - 1);
        root->right = doBuild(preorder, inorder, start_p + index_i - start_i + 1, end_p, index_i + 1, end_i);
        return root;
    }

    int Find(const vector<int>& inorder, int start, int end, int value) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1;
    }
};