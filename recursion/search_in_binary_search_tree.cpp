/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/3233/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        root = doSearch(root, val);
        return root;
    }

    TreeNode* doSearch(TreeNode* root, int val) {
        if (!root) {
            return root;
        }

        if (root->val == val) {
            return root;
        }

        if (root->val > val) {
            return doSearch(root->left, val);
        }
        
        return doSearch(root->right, val);
    }
};