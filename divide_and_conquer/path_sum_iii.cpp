/**
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 找出路径和等于给定数值的路径总数。
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 二叉树不超过 1000 个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 二叉树结点的定义
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int pathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return 0;
    }
    return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int count(TreeNode* node, int sum) {
    if (node == nullptr) {
        return 0;
    }
    return (node->val == sum) + count(node->left, sum - node->val) + count(node->right, sum - node->val);
}