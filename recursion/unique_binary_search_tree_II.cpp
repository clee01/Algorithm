/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/253/conclusion/2384/
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
    vector<TreeNode*> generateTrees(int n) {
        return doGenerate(0, n - 1);
    }

    vector<TreeNode*> doGenerate(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = doGenerate(start, i - 1);
            vector<TreeNode*> right = doGenerate(i + 1, end);
            for (auto it_left : left) {
                for (auto it_right : right) {
                    TreeNode* root = new TreeNode(i + 1, it_left, it_right);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};